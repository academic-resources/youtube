/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSHTMLAnchorElement.h"

#include "HTMLAnchorElement.h"
#include "HTMLNames.h"
#include "KURL.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLAnchorElement);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLAnchorElementTableValues[21] =
{
    { "accessKey", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementAccessKey), (intptr_t)setJSHTMLAnchorElementAccessKey THUNK_GENERATOR(0) },
    { "charset", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementCharset), (intptr_t)setJSHTMLAnchorElementCharset THUNK_GENERATOR(0) },
    { "coords", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementCoords), (intptr_t)setJSHTMLAnchorElementCoords THUNK_GENERATOR(0) },
    { "href", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementHref), (intptr_t)setJSHTMLAnchorElementHref THUNK_GENERATOR(0) },
    { "hreflang", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementHreflang), (intptr_t)setJSHTMLAnchorElementHreflang THUNK_GENERATOR(0) },
    { "name", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementName), (intptr_t)setJSHTMLAnchorElementName THUNK_GENERATOR(0) },
    { "rel", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementRel), (intptr_t)setJSHTMLAnchorElementRel THUNK_GENERATOR(0) },
    { "rev", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementRev), (intptr_t)setJSHTMLAnchorElementRev THUNK_GENERATOR(0) },
    { "shape", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementShape), (intptr_t)setJSHTMLAnchorElementShape THUNK_GENERATOR(0) },
    { "target", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementTarget), (intptr_t)setJSHTMLAnchorElementTarget THUNK_GENERATOR(0) },
    { "type", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementType), (intptr_t)setJSHTMLAnchorElementType THUNK_GENERATOR(0) },
    { "hash", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementHash), (intptr_t)setJSHTMLAnchorElementHash THUNK_GENERATOR(0) },
    { "host", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementHost), (intptr_t)setJSHTMLAnchorElementHost THUNK_GENERATOR(0) },
    { "hostname", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementHostname), (intptr_t)setJSHTMLAnchorElementHostname THUNK_GENERATOR(0) },
    { "pathname", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementPathname), (intptr_t)setJSHTMLAnchorElementPathname THUNK_GENERATOR(0) },
    { "port", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementPort), (intptr_t)setJSHTMLAnchorElementPort THUNK_GENERATOR(0) },
    { "protocol", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementProtocol), (intptr_t)setJSHTMLAnchorElementProtocol THUNK_GENERATOR(0) },
    { "search", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementSearch), (intptr_t)setJSHTMLAnchorElementSearch THUNK_GENERATOR(0) },
    { "text", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementText), (intptr_t)0 THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLAnchorElementConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLAnchorElementTable = { 67, 63, JSHTMLAnchorElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLAnchorElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLAnchorElementConstructorTable = { 1, 0, JSHTMLAnchorElementConstructorTableValues, 0 };
class JSHTMLAnchorElementConstructor : public DOMConstructorObject {
public:
    JSHTMLAnchorElementConstructor(JSC::ExecState*, JSDOMGlobalObject*);

    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | JSC::ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLAnchorElementConstructor::s_info = { "HTMLAnchorElementConstructor", 0, &JSHTMLAnchorElementConstructorTable, 0 };

JSHTMLAnchorElementConstructor::JSHTMLAnchorElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSHTMLAnchorElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSHTMLAnchorElementPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSHTMLAnchorElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLAnchorElementConstructor, DOMObject>(exec, &JSHTMLAnchorElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLAnchorElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLAnchorElementConstructor, DOMObject>(exec, &JSHTMLAnchorElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLAnchorElementPrototypeTableValues[2] =
{
    { "toString", DontDelete | DontEnum | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLAnchorElementPrototypeFunctionToString), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLAnchorElementPrototypeTable = { 2, 1, JSHTMLAnchorElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLAnchorElementPrototype::s_info = { "HTMLAnchorElementPrototype", 0, &JSHTMLAnchorElementPrototypeTable, 0 };

JSObject* JSHTMLAnchorElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLAnchorElement>(exec, globalObject);
}

bool JSHTMLAnchorElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLAnchorElementPrototypeTable, this, propertyName, slot);
}

bool JSHTMLAnchorElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLAnchorElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLAnchorElement::s_info = { "HTMLAnchorElement", &JSHTMLElement::s_info, &JSHTMLAnchorElementTable, 0 };

JSHTMLAnchorElement::JSHTMLAnchorElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLAnchorElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLAnchorElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLAnchorElementPrototype(globalObject, JSHTMLAnchorElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLAnchorElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLAnchorElement, Base>(exec, &JSHTMLAnchorElementTable, this, propertyName, slot);
}

bool JSHTMLAnchorElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLAnchorElement, Base>(exec, &JSHTMLAnchorElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLAnchorElementAccessKey(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::accesskeyAttr));
    return result;
}

JSValue jsHTMLAnchorElementCharset(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::charsetAttr));
    return result;
}

JSValue jsHTMLAnchorElementCoords(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::coordsAttr));
    return result;
}

JSValue jsHTMLAnchorElementHref(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getURLAttribute(WebCore::HTMLNames::hrefAttr));
    return result;
}

JSValue jsHTMLAnchorElementHreflang(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::hreflangAttr));
    return result;
}

JSValue jsHTMLAnchorElementName(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::nameAttr));
    return result;
}

JSValue jsHTMLAnchorElementRel(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::relAttr));
    return result;
}

JSValue jsHTMLAnchorElementRev(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::revAttr));
    return result;
}

JSValue jsHTMLAnchorElementShape(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::shapeAttr));
    return result;
}

JSValue jsHTMLAnchorElementTarget(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::targetAttr));
    return result;
}

JSValue jsHTMLAnchorElementType(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::typeAttr));
    return result;
}

JSValue jsHTMLAnchorElementHash(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->hash());
    return result;
}

JSValue jsHTMLAnchorElementHost(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->host());
    return result;
}

JSValue jsHTMLAnchorElementHostname(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->hostname());
    return result;
}

JSValue jsHTMLAnchorElementPathname(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->pathname());
    return result;
}

JSValue jsHTMLAnchorElementPort(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->port());
    return result;
}

JSValue jsHTMLAnchorElementProtocol(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->protocol());
    return result;
}

JSValue jsHTMLAnchorElementSearch(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->search());
    return result;
}

JSValue jsHTMLAnchorElementText(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->text());
    return result;
}

JSValue jsHTMLAnchorElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLAnchorElement* domObject = static_cast<JSHTMLAnchorElement*>(asObject(slotBase));
    return JSHTMLAnchorElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLAnchorElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLAnchorElement, Base>(exec, propertyName, value, &JSHTMLAnchorElementTable, this, slot);
}

void setJSHTMLAnchorElementAccessKey(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::accesskeyAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementCharset(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::charsetAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementCoords(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::coordsAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementHref(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::hrefAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementHreflang(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::hreflangAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementName(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::nameAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementRel(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::relAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementRev(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::revAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementShape(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::shapeAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementTarget(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::targetAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementType(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::typeAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementHash(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setHash(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementHost(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setHost(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementHostname(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setHostname(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementPathname(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setPathname(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementPort(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setPort(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementProtocol(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setProtocol(valueToStringWithNullCheck(exec, value));
}

void setJSHTMLAnchorElementSearch(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(thisObject);
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());
    imp->setSearch(valueToStringWithNullCheck(exec, value));
}

JSValue JSHTMLAnchorElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLAnchorElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsHTMLAnchorElementPrototypeFunctionToString(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLAnchorElement::s_info))
        return throwVMTypeError(exec);
    JSHTMLAnchorElement* castedThis = static_cast<JSHTMLAnchorElement*>(asObject(thisValue));
    HTMLAnchorElement* imp = static_cast<HTMLAnchorElement*>(castedThis->impl());


    JSC::JSValue result = jsString(exec, imp->toString());
    return JSValue::encode(result);
}


}