/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2007 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2014 FactorY Media Production GmbH
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "JSCallbackObject.h"

#include "Collector.h"
#include <wtf/text/StringHash.h>

namespace JSC {

ASSERT_CLASS_FITS_IN_CELL(JSCallbackObject<JSObjectWithGlobalObject>);
ASSERT_CLASS_FITS_IN_CELL(JSCallbackObject<JSGlobalObject>);

// Define the two types of JSCallbackObjects we support.
/* FYWEBKITMOD BEGIN */
#if PLATFORM(FYMP) && FYMP_PLATFORM == FYMP_PLATFORM_WIIU

__asm(
"	.rodata\n" \
"classNameJSObjectWithGlobalObject:\n" \
"	.asciz	\"CallbackGlobalObject\"\n" \
"classNameJSGlobalObject:\n" \
"	.asciz	\"CallbackObject\"\n" \
"\n" \
"	.global info__Q2_3JSC58JSCallbackObject__tm__34_Q2_3JSC24JSObjectWithGlobalObject\n" \
"	.global	info__Q2_3JSC48JSCallbackObject__tm__24_Q2_3JSC14JSGlobalObject\n" \
"\n" \
"	.align 2\n" \
"info__Q2_3JSC58JSCallbackObject__tm__34_Q2_3JSC24JSObjectWithGlobalObject:\n" \
"	.long classNameJSObjectWithGlobalObject, 0, 0, 0\n" \
"info__Q2_3JSC48JSCallbackObject__tm__24_Q2_3JSC14JSGlobalObject:\n" \
"	.long classNameJSGlobalObject, 0, 0, 0\n");

/* FYWEBKITMOD END */
#else
// the original definition
template <> const ClassInfo JSCallbackObject<JSObjectWithGlobalObject>::info = { "CallbackObject", 0, 0, 0 };
template <> const ClassInfo JSCallbackObject<JSGlobalObject>::info = { "CallbackGlobalObject", 0, 0, 0 };
#endif

} // namespace JSC

