/*
 * Copyright (C) 2010, 2013 Apple Inc. All rights reserved.
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

// FYMP - file integrated from r152754

#include "config.h"
#include <wtf/text/StringBuilder.h>

//#include "IntegerToStringConversion.h" // FYMP
#include "WTFString.h"

namespace WTF {

static size_t expandedCapacity(size_t capacity, size_t newLength)
{
    static const size_t minimumCapacity = 16;
    return std::max(capacity, std::max(minimumCapacity, newLength * 2));
}

void StringBuilder2::reifyString() const
{
    // Check if the string already exists.
    if (!m_string.isNull()) {
        ASSERT(m_string.length() == m_length);
        return;
    }

    // Check for empty.
    if (!m_length) {
        m_string = WebCore::StringImpl::empty();
        return;
    }

    // Must be valid in the buffer, take a substring (unless string fills the buffer).
    ASSERT(m_buffer && m_length <= m_buffer->length());
    m_string = (m_length == m_buffer->length())
        ? m_buffer.get()
        : WebCore::StringImpl::create(m_buffer, 0, m_length);

//    if (m_buffer->has16BitShadow() && m_valid16BitShadowLength < m_length) // FYMP
//        m_buffer->upconvertCharacters(m_valid16BitShadowLength, m_length); // FYMP

//    m_valid16BitShadowLength = m_length; // FYMP
}

void StringBuilder2::resize(unsigned newSize)
{
    // Check newSize < m_length, hence m_length > 0.
    ASSERT(newSize <= m_length);
    if (newSize == m_length)
        return;
    ASSERT(m_length);

    // If there is a buffer, we only need to duplicate it if it has more than one ref.
    if (m_buffer) {
        m_string = WebCore::String(); // Clear the string to remove the reference to m_buffer if any before checking the reference count of m_buffer.
        if (!m_buffer->hasOneRef()) {
/* FYMP begin
            if (m_buffer->is8Bit())
                allocateBuffer(m_buffer->characters8(), m_buffer->length());
            else
                allocateBuffer(m_buffer->characters16(), m_buffer->length());
*/
		allocateBuffer(m_buffer->characters(), m_buffer->length());
// FYMP end
        }
        m_length = newSize;
        return;
    }

    // Since m_length && !m_buffer, the string must be valid in m_string, and m_string.length() > 0.
    ASSERT(!m_string.isEmpty());
    ASSERT(m_length == m_string.length());
    ASSERT(newSize < m_string.length());
    m_length = newSize;
    m_string = WebCore::StringImpl::create(m_string.impl(), 0, newSize);
}

/* FYMP begin - keeping old WTFString which is 16bit
// Allocate a new 8 bit buffer, copying in currentCharacters (these may come from either m_string
// or m_buffer, neither will be reassigned until the copy has completed).
void StringBuilder2::allocateBuffer(const LChar* currentCharacters, unsigned requiredLength)
{
    ASSERT(m_is8Bit);
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<WebCore::StringImpl> buffer = WebCore::StringImpl::createUninitialized(requiredLength, m_bufferCharacters8);
    memcpy(m_bufferCharacters8, currentCharacters, static_cast<size_t>(m_length) * sizeof(LChar)); // This can't overflow.
    
    // Update the builder state.
    m_buffer = buffer.release();
    m_string = String();
}
FYMP end */

// Allocate a new 16 bit buffer, copying in currentCharacters (these may come from either m_string
// or m_buffer,  neither will be reassigned until the copy has completed).
void StringBuilder2::allocateBuffer(const UChar* currentCharacters, unsigned requiredLength)
{
//    ASSERT(!m_is8Bit); FYMP
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<WebCore::StringImpl> buffer = WebCore::StringImpl::createUninitialized(requiredLength, m_bufferCharacters16);
    memcpy(m_bufferCharacters16, currentCharacters, static_cast<size_t>(m_length) * sizeof(UChar)); // This can't overflow.
    
    // Update the builder state.
    m_buffer = buffer.release();
    m_string = WebCore::String();
}

/* FYMP end - keeping old 16bit WTFString in the background
// Allocate a new 16 bit buffer, copying in currentCharacters (which is 8 bit and may come
// from either m_string or m_buffer, neither will be reassigned until the copy has completed).
void StringBuilder2::allocateBufferUpConvert(const LChar* currentCharacters, unsigned requiredLength)
{
    ASSERT(m_is8Bit);
    // Copy the existing data into a new buffer, set result to point to the end of the existing data.
    RefPtr<StringImpl> buffer = StringImpl::createUninitialized(requiredLength, m_bufferCharacters16);
    for (unsigned i = 0; i < m_length; ++i)
        m_bufferCharacters16[i] = currentCharacters[i];
    
    m_is8Bit = false;
    
    // Update the builder state.
    m_buffer = buffer.release();
    m_string = String();
}
FYMP end */

/* FYMP begin
template <>
void StringBuilder2::reallocateBuffer<LChar>(unsigned requiredLength)
{
    // If the buffer has only one ref (by this StringBuilder2), reallocate it,
    // otherwise fall back to "allocate and copy" method.
    m_string = String();
    
    ASSERT(m_is8Bit);
    ASSERT(m_buffer->is8Bit());
    
    if (m_buffer->hasOneRef())
        m_buffer = StringImpl::reallocate(m_buffer.release(), requiredLength, m_bufferCharacters8);
    else
        allocateBuffer(m_buffer->characters8(), requiredLength);
}
*/

/* FYMP begin - keeping old 16bit WTFString in the background
template <>
void StringBuilder2::reallocateBuffer<UChar>(unsigned requiredLength)
{
    // If the buffer has only one ref (by this StringBuilder2), reallocate it,
    // otherwise fall back to "allocate and copy" method.
    m_string = WebCore::String();

    if (m_buffer->is8Bit())
        allocateBufferUpConvert(m_buffer->characters8(), requiredLength);
    else if (m_buffer->hasOneRef())
        m_buffer = StringImpl::reallocate(m_buffer.release(), requiredLength, m_bufferCharacters16);
    else
        allocateBuffer(m_buffer->characters16(), requiredLength);

	if (m_buffer->hasOneRef())
		m_buffer = WebCore::StringImpl::reallocate(m_buffer.release(), requiredLength, m_bufferCharacters16);
	else
		allocateBuffer(m_buffer->characters16(), requiredLength);
}*/

void StringBuilder2::reallocateBuffer/*<UChar>*/(unsigned requiredLength)
{
    // If the buffer has only one ref (by this StringBuilder2), reallocate it,
    // otherwise fall back to "allocate and copy" method.
    m_string = WebCore::String();

	if (m_buffer->hasOneRef())
		m_buffer = WebCore::StringImpl::reallocate(m_buffer.release(), requiredLength, m_bufferCharacters16);
	else
		allocateBuffer(m_buffer->characters16(), requiredLength);
}
// FYMP end

// FYMP begin
/*
void StringBuilder2::reserveCapacity(unsigned newCapacity)
{
    if (m_buffer) {
        // If there is already a buffer, then grow if necessary.
        if (newCapacity > m_buffer->length()) {
			if (m_buffer->is8Bit())
                reallocateBuffer<LChar>(newCapacity);
    		else
                reallocateBuffer<UChar>(newCapacity);
        }
    } else {
        // Grow the string, if necessary.
        if (newCapacity > m_length) {
            if (!m_length) {
                LChar* nullPlaceholder = 0;
                allocateBuffer(nullPlaceholder, newCapacity);
            }
			 else if (m_string.is8Bit())
                allocateBuffer(m_string.characters8(), newCapacity);
            else
                allocateBuffer(m_string.characters16(), newCapacity);
        }
    }
}
*/

void StringBuilder2::reserveCapacity(unsigned newCapacity)
{
    if (m_buffer) {
        // If there is already a buffer, then grow if necessary.
        if (newCapacity > m_buffer->length()) {
			reallocateBuffer/*<UChar> FYMP*/(newCapacity);
        }
    } else {
        // Grow the string, if necessary.
        if (newCapacity > m_length) {
            if (!m_length) {
				UChar* nullPlaceholder = 0;    // FYMP
                allocateBuffer(nullPlaceholder, newCapacity);
            }
            else
                allocateBuffer(m_string.characters16(), newCapacity);
        }
    }
}
// FYMP end

// Make 'length' additional capacity be available in m_buffer, update m_string & m_length,
// return a pointer to the newly allocated storage.

// FYMP begin - chagned CharType to UChar
//template <typename CharType>
ALWAYS_INLINE UChar* StringBuilder2::appendUninitialized(unsigned length)
{
    ASSERT(length);

    // Calculate the new size of the builder after appending.
    unsigned requiredLength = length + m_length;
    if (requiredLength < length)
        CRASH();

    if ((m_buffer) && (requiredLength <= m_buffer->length())) {
        // If the buffer is valid it must be at least as long as the current builder contents!
        ASSERT(m_buffer->length() >= m_length);
        unsigned currentLength = m_length;
        m_string = WebCore::String();
        m_length = requiredLength;
        return getBufferCharacters() + currentLength;
    }
    
    return appendUninitializedSlow(requiredLength);
}
// FYMP end

// Make 'length' additional capacity be available in m_buffer, update m_string & m_length,
// return a pointer to the newly allocated storage.
// FYMP begin - chagned CharType to UChar*
//template <typename CharType>
//CharType* StringBuilder2::appendUninitializedSlow(unsigned requiredLength)
UChar* StringBuilder2::appendUninitializedSlow(unsigned requiredLength)
{
    ASSERT(requiredLength);

    if (m_buffer) {
        // If the buffer is valid it must be at least as long as the current builder contents!
        ASSERT(m_buffer->length() >= m_length);
        
        reallocateBuffer/*<CharType>*/(expandedCapacity(capacity(), requiredLength));
    } else {
        ASSERT(m_string.length() == m_length);
        allocateBuffer(m_length ? m_string.characters() : 0, expandedCapacity(capacity(), requiredLength));
    }
    
    UChar* result = getBufferCharacters() + m_length;
    m_length = requiredLength;
    return result;
}
// FYMP end

// FYMP begin - keeping old 16bit WTFString in the background.
/*
void StringBuilder2::append(const UChar* characters, unsigned length)
{
    if (!length)
        return;

    ASSERT(characters);
    if (m_is8Bit) {
        if (length == 1 && !(*characters & ~0xff)) {
            // Append as 8 bit character
            LChar lChar = static_cast<LChar>(*characters);
            append(&lChar, 1);
            return;
        }
	
        // Calculate the new size of the builder after appending.
        unsigned requiredLength = length + m_length;
        if (requiredLength < length)
            CRASH();
        
        if (m_buffer) {
            // If the buffer is valid it must be at least as long as the current builder contents!
            ASSERT(m_buffer->length() >= m_length);
            
            allocateBufferUpConvert(m_buffer->characters8(), expandedCapacity(capacity(), requiredLength));
        } else {
            ASSERT(m_string.length() == m_length);
            allocateBufferUpConvert(m_string.isNull() ? 0 : m_string.characters8(), expandedCapacity(capacity(), requiredLength));
        }
	

        memcpy(m_bufferCharacters16 + m_length, characters, static_cast<size_t>(length) * sizeof(UChar));        
        m_length = requiredLength;
    } else
        memcpy(appendUninitialized<UChar>(length), characters, static_cast<size_t>(length) * sizeof(UChar));
}
*/
void StringBuilder2::append(const UChar* characters, unsigned length)
{
    if (!length)
        return;

    ASSERT(characters);
    memcpy(appendUninitialized/*FYMP <UChar>*/(length), characters, static_cast<size_t>(length) * sizeof(UChar));
}
// FYMP end

void StringBuilder2::append(const LChar* characters, unsigned length)
{
    if (!length)
        return;
    ASSERT(characters);

/* FYMP begin - keeping old 16bit WTFString in the background
    if (m_is8Bit) {
        LChar* dest = appendUninitialized<LChar>(length);
        if (length > 8)
            memcpy(dest, characters, static_cast<size_t>(length) * sizeof(LChar));
        else {
            const LChar* end = characters + length;
            while (characters < end)
                *(dest++) = *(characters++);
        }
    } else FYMP end */ {
        UChar* dest = appendUninitialized(length);
        const LChar* end = characters + length;
        while (characters < end)
            *(dest++) = *(characters++);
    }
}



void StringBuilder2::appendNumber(int number)
{
//    numberToStringSigned<WebCore::StringBuilder2>(number, this); // FYMP
	append(WebCore::String::number(number));
}

void StringBuilder2::appendNumber(unsigned int number)
{
//    numberToStringUnsigned<WebCore::StringBuilder2>(number, this); // FYMP
	append(WebCore::String::number(number));
}

void StringBuilder2::appendNumber(long number)
{
//    numberToStringSigned<WebCore::StringBuilder2>(number, this); // FYMP
	append(WebCore::String::number(number));
}

void StringBuilder2::appendNumber(unsigned long number)
{
//    numberToStringUnsigned<WebCore::StringBuilder2>(number, this); // FYMP
	append(WebCore::String::number(number));
}

void StringBuilder2::appendNumber(long long number)
{
//    numberToStringSigned<WebCore::StringBuilder2>(number, this); // FYMP
	append(WebCore::String::number(number));
}

void StringBuilder2::appendNumber(unsigned long long number) // FYMP
{
//    numberToStringUnsigned<WebCore::StringBuilder2>(number, this);
	append(WebCore::String::number(number));
}

bool StringBuilder2::canShrink() const
{
    // Only shrink the buffer if it's less than 80% full. Need to tune this heuristic!
    return m_buffer && m_buffer->length() > (m_length + (m_length >> 2));
}

void StringBuilder2::shrinkToFit()
{
    if (canShrink()) {
/* FYMP begin - keeping old 16bit WTFString in the background
        if (m_is8Bit)
            reallocateBuffer<LChar>(m_length);
        else
		FYMP end */
            reallocateBuffer/*<UChar>*/(m_length);
        m_string = m_buffer;
        m_buffer = 0;
    }
}

} // namespace WTF

