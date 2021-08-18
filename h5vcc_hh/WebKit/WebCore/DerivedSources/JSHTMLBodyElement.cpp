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
#include "JSHTMLBodyElement.h"

#include "EventListener.h"
#include "HTMLBodyElement.h"
#include "HTMLNames.h"
#include "JSEventListener.h"
#include "KURL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLBodyElement);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLBodyElementTableValues[21] =
{
    { "aLink", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementALink), (intptr_t)setJSHTMLBodyElementALink THUNK_GENERATOR(0) },
    { "background", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementBackground), (intptr_t)setJSHTMLBodyElementBackground THUNK_GENERATOR(0) },
    { "bgColor", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementBgColor), (intptr_t)setJSHTMLBodyElementBgColor THUNK_GENERATOR(0) },
    { "link", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementLink), (intptr_t)setJSHTMLBodyElementLink THUNK_GENERATOR(0) },
    { "text", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementText), (intptr_t)setJSHTMLBodyElementText THUNK_GENERATOR(0) },
    { "vLink", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementVLink), (intptr_t)setJSHTMLBodyElementVLink THUNK_GENERATOR(0) },
    { "onbeforeunload", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnbeforeunload), (intptr_t)setJSHTMLBodyElementOnbeforeunload THUNK_GENERATOR(0) },
    { "onhashchange", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnhashchange), (intptr_t)setJSHTMLBodyElementOnhashchange THUNK_GENERATOR(0) },
    { "onmessage", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnmessage), (intptr_t)setJSHTMLBodyElementOnmessage THUNK_GENERATOR(0) },
    { "onoffline", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnoffline), (intptr_t)setJSHTMLBodyElementOnoffline THUNK_GENERATOR(0) },
    { "ononline", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnonline), (intptr_t)setJSHTMLBodyElementOnonline THUNK_GENERATOR(0) },
    { "onpopstate", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnpopstate), (intptr_t)setJSHTMLBodyElementOnpopstate THUNK_GENERATOR(0) },
    { "onresize", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnresize), (intptr_t)setJSHTMLBodyElementOnresize THUNK_GENERATOR(0) },
    { "onstorage", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnstorage), (intptr_t)setJSHTMLBodyElementOnstorage THUNK_GENERATOR(0) },
    { "onunload", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnunload), (intptr_t)setJSHTMLBodyElementOnunload THUNK_GENERATOR(0) },
    { "onblur", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnblur), (intptr_t)setJSHTMLBodyElementOnblur THUNK_GENERATOR(0) },
    { "onerror", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnerror), (intptr_t)setJSHTMLBodyElementOnerror THUNK_GENERATOR(0) },
    { "onfocus", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnfocus), (intptr_t)setJSHTMLBodyElementOnfocus THUNK_GENERATOR(0) },
    { "onload", DontDelete | DontEnum, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementOnload), (intptr_t)setJSHTMLBodyElementOnload THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLBodyElementConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLBodyElementTable = { 64, 63, JSHTMLBodyElementTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLBodyElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLBodyElementConstructorTable = { 1, 0, JSHTMLBodyElementConstructorTableValues, 0 };
class JSHTMLBodyElementConstructor : public DOMConstructorObject {
public:
    JSHTMLBodyElementConstructor(JSC::ExecState*, JSDOMGlobalObject*);

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

const ClassInfo JSHTMLBodyElementConstructor::s_info = { "HTMLBodyElementConstructor", 0, &JSHTMLBodyElementConstructorTable, 0 };

JSHTMLBodyElementConstructor::JSHTMLBodyElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSHTMLBodyElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSHTMLBodyElementPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSHTMLBodyElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLBodyElementConstructor, DOMObject>(exec, &JSHTMLBodyElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLBodyElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLBodyElementConstructor, DOMObject>(exec, &JSHTMLBodyElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLBodyElementPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLBodyElementPrototypeTable = { 1, 0, JSHTMLBodyElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLBodyElementPrototype::s_info = { "HTMLBodyElementPrototype", 0, &JSHTMLBodyElementPrototypeTable, 0 };

JSObject* JSHTMLBodyElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLBodyElement>(exec, globalObject);
}

const ClassInfo JSHTMLBodyElement::s_info = { "HTMLBodyElement", &JSHTMLElement::s_info, &JSHTMLBodyElementTable, 0 };

JSHTMLBodyElement::JSHTMLBodyElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLBodyElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLBodyElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLBodyElementPrototype(globalObject, JSHTMLBodyElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLBodyElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLBodyElement, Base>(exec, &JSHTMLBodyElementTable, this, propertyName, slot);
}

bool JSHTMLBodyElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLBodyElement, Base>(exec, &JSHTMLBodyElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLBodyElementALink(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::alinkAttr));
    return result;
}

JSValue jsHTMLBodyElementBackground(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::backgroundAttr));
    return result;
}

JSValue jsHTMLBodyElementBgColor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::bgcolorAttr));
    return result;
}

JSValue jsHTMLBodyElementLink(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::linkAttr));
    return result;
}

JSValue jsHTMLBodyElementText(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::textAttr));
    return result;
}

JSValue jsHTMLBodyElementVLink(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    JSValue result = jsString(exec, imp->getAttribute(WebCore::HTMLNames::vlinkAttr));
    return result;
}

JSValue jsHTMLBodyElementOnbeforeunload(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onbeforeunload()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnhashchange(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onhashchange()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnmessage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onmessage()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnoffline(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onoffline()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnonline(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->ononline()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnpopstate(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onpopstate()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnresize(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onresize()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnstorage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onstorage()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnunload(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onunload()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnblur(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onblur()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnerror(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onerror()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnfocus(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onfocus()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementOnload(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    if (EventListener* listener = imp->onload()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsHTMLBodyElementConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLBodyElement* domObject = static_cast<JSHTMLBodyElement*>(asObject(slotBase));
    return JSHTMLBodyElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLBodyElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSHTMLBodyElement, Base>(exec, propertyName, value, &JSHTMLBodyElementTable, this, slot);
}

void setJSHTMLBodyElementALink(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::alinkAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementBackground(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::backgroundAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementBgColor(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::bgcolorAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementLink(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::linkAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementText(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::textAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementVLink(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(castedThis->impl());
    imp->setAttribute(WebCore::HTMLNames::vlinkAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLBodyElementOnbeforeunload(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnbeforeunload(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnhashchange(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnhashchange(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnmessage(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnmessage(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnoffline(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnoffline(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnonline(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnonline(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnpopstate(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnpopstate(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnresize(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnresize(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnstorage(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnstorage(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnunload(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnunload(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnblur(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnblur(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnerror(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnerror(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnfocus(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnfocus(createJSAttributeEventListener(exec, value, globalObject));
}

void setJSHTMLBodyElementOnload(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    JSHTMLBodyElement* castedThis = static_cast<JSHTMLBodyElement*>(thisObject);
    JSDOMGlobalObject* globalObject = castedThis->globalObject();
    HTMLBodyElement* imp = static_cast<HTMLBodyElement*>(static_cast<JSHTMLBodyElement*>(thisObject)->impl());
    imp->setOnload(createJSAttributeEventListener(exec, value, globalObject));
}

JSValue JSHTMLBodyElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLBodyElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}
