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
#include "JSDOMImplementation.h"

#include "CSSStyleSheet.h"
#include "DOMImplementation.h"
#include "Document.h"
#include "DocumentType.h"
#include "HTMLDocument.h"
#include "JSCSSStyleSheet.h"
#include "JSDocument.h"
#include "JSDocumentType.h"
#include "JSHTMLDocument.h"
#include "NodeFilter.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSDOMImplementation);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMImplementationTableValues[2] =
{
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDOMImplementationConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMImplementationTable = { 2, 1, JSDOMImplementationTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMImplementationConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMImplementationConstructorTable = { 1, 0, JSDOMImplementationConstructorTableValues, 0 };
class JSDOMImplementationConstructor : public DOMConstructorObject {
public:
    JSDOMImplementationConstructor(JSC::ExecState*, JSDOMGlobalObject*);

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

const ClassInfo JSDOMImplementationConstructor::s_info = { "DOMImplementationConstructor", 0, &JSDOMImplementationConstructorTable, 0 };

JSDOMImplementationConstructor::JSDOMImplementationConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSDOMImplementationConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSDOMImplementationPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSDOMImplementationConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDOMImplementationConstructor, DOMObject>(exec, &JSDOMImplementationConstructorTable, this, propertyName, slot);
}

bool JSDOMImplementationConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDOMImplementationConstructor, DOMObject>(exec, &JSDOMImplementationConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSDOMImplementationPrototypeTableValues[6] =
{
    { "hasFeature", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDOMImplementationPrototypeFunctionHasFeature), (intptr_t)2 THUNK_GENERATOR(0) },
    { "createDocumentType", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDOMImplementationPrototypeFunctionCreateDocumentType), (intptr_t)3 THUNK_GENERATOR(0) },
    { "createDocument", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDOMImplementationPrototypeFunctionCreateDocument), (intptr_t)3 THUNK_GENERATOR(0) },
    { "createCSSStyleSheet", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDOMImplementationPrototypeFunctionCreateCSSStyleSheet), (intptr_t)2 THUNK_GENERATOR(0) },
    { "createHTMLDocument", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsDOMImplementationPrototypeFunctionCreateHTMLDocument), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSDOMImplementationPrototypeTable = { 17, 15, JSDOMImplementationPrototypeTableValues, 0 };
const ClassInfo JSDOMImplementationPrototype::s_info = { "DOMImplementationPrototype", 0, &JSDOMImplementationPrototypeTable, 0 };

JSObject* JSDOMImplementationPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDOMImplementation>(exec, globalObject);
}

bool JSDOMImplementationPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSDOMImplementationPrototypeTable, this, propertyName, slot);
}

bool JSDOMImplementationPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSDOMImplementationPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSDOMImplementation::s_info = { "DOMImplementation", 0, &JSDOMImplementationTable, 0 };

JSDOMImplementation::JSDOMImplementation(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<DOMImplementation> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSDOMImplementation::~JSDOMImplementation()
{
    forgetDOMObject(this, impl());
}

JSObject* JSDOMImplementation::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSDOMImplementationPrototype(globalObject, JSDOMImplementationPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSDOMImplementation::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDOMImplementation, Base>(exec, &JSDOMImplementationTable, this, propertyName, slot);
}

bool JSDOMImplementation::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSDOMImplementation, Base>(exec, &JSDOMImplementationTable, this, propertyName, descriptor);
}

JSValue jsDOMImplementationConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSDOMImplementation* domObject = static_cast<JSDOMImplementation*>(asObject(slotBase));
    return JSDOMImplementation::getConstructor(exec, domObject->globalObject());
}
JSValue JSDOMImplementation::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDOMImplementationConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsDOMImplementationPrototypeFunctionHasFeature(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDOMImplementation::s_info))
        return throwVMTypeError(exec);
    JSDOMImplementation* castedThis = static_cast<JSDOMImplementation*>(asObject(thisValue));
    DOMImplementation* imp = static_cast<DOMImplementation*>(castedThis->impl());
    const String& feature = ustringToString(exec->argument(0).toString(exec));
    const String& version = valueToStringWithNullCheck(exec, exec->argument(1));


    JSC::JSValue result = jsBoolean(imp->hasFeature(feature, version));
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsDOMImplementationPrototypeFunctionCreateDocumentType(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDOMImplementation::s_info))
        return throwVMTypeError(exec);
    JSDOMImplementation* castedThis = static_cast<JSDOMImplementation*>(asObject(thisValue));
    DOMImplementation* imp = static_cast<DOMImplementation*>(castedThis->impl());
    ExceptionCode ec = 0;
    const String& qualifiedName = valueToStringWithUndefinedOrNullCheck(exec, exec->argument(0));
    const String& publicId = valueToStringWithUndefinedOrNullCheck(exec, exec->argument(1));
    const String& systemId = valueToStringWithUndefinedOrNullCheck(exec, exec->argument(2));


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->createDocumentType(qualifiedName, publicId, systemId, ec)));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsDOMImplementationPrototypeFunctionCreateDocument(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDOMImplementation::s_info))
        return throwVMTypeError(exec);
    JSDOMImplementation* castedThis = static_cast<JSDOMImplementation*>(asObject(thisValue));
    DOMImplementation* imp = static_cast<DOMImplementation*>(castedThis->impl());
    ExceptionCode ec = 0;
    const String& namespaceURI = valueToStringWithNullCheck(exec, exec->argument(0));
    const String& qualifiedName = valueToStringWithNullCheck(exec, exec->argument(1));
    DocumentType* doctype = toDocumentType(exec->argument(2));


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->createDocument(namespaceURI, qualifiedName, doctype, ec)));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsDOMImplementationPrototypeFunctionCreateCSSStyleSheet(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDOMImplementation::s_info))
        return throwVMTypeError(exec);
    JSDOMImplementation* castedThis = static_cast<JSDOMImplementation*>(asObject(thisValue));
    DOMImplementation* imp = static_cast<DOMImplementation*>(castedThis->impl());
    ExceptionCode ec = 0;
    const String& title = ustringToString(exec->argument(0).toString(exec));
    const String& media = ustringToString(exec->argument(1).toString(exec));


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->createCSSStyleSheet(title, media, ec)));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsDOMImplementationPrototypeFunctionCreateHTMLDocument(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSDOMImplementation::s_info))
        return throwVMTypeError(exec);
    JSDOMImplementation* castedThis = static_cast<JSDOMImplementation*>(asObject(thisValue));
    DOMImplementation* imp = static_cast<DOMImplementation*>(castedThis->impl());
    const String& title = ustringToString(exec->argument(0).toString(exec));


    JSC::JSValue result = toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->createHTMLDocument(title)));
    return JSValue::encode(result);
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, DOMImplementation* object)
{
    return getDOMObjectWrapper<JSDOMImplementation>(exec, globalObject, object);
}
DOMImplementation* toDOMImplementation(JSC::JSValue value)
{
    return value.inherits(&JSDOMImplementation::s_info) ? static_cast<JSDOMImplementation*>(asObject(value))->impl() : 0;
}

}
