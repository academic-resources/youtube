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
#include "JSHTMLOptionsCollection.h"

#include "HTMLOptionsCollection.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLOptionsCollection);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOptionsCollectionTableValues[4] =
{
    { "selectedIndex", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionSelectedIndex), (intptr_t)setJSHTMLOptionsCollectionSelectedIndex THUNK_GENERATOR(0) },
    { "length", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionLength), (intptr_t)setJSHTMLOptionsCollectionLength THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLOptionsCollectionConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionTable = { 9, 7, JSHTMLOptionsCollectionTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOptionsCollectionConstructorTableValues[1] =
{
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionConstructorTable = { 1, 0, JSHTMLOptionsCollectionConstructorTableValues, 0 };
class JSHTMLOptionsCollectionConstructor : public DOMConstructorObject {
public:
    JSHTMLOptionsCollectionConstructor(JSC::ExecState*, JSDOMGlobalObject*);

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

const ClassInfo JSHTMLOptionsCollectionConstructor::s_info = { "HTMLOptionsCollectionConstructor", 0, &JSHTMLOptionsCollectionConstructorTable, 0 };

JSHTMLOptionsCollectionConstructor::JSHTMLOptionsCollectionConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSHTMLOptionsCollectionConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSHTMLOptionsCollectionPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSHTMLOptionsCollectionConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionsCollectionConstructor, DOMObject>(exec, &JSHTMLOptionsCollectionConstructorTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollectionConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionsCollectionConstructor, DOMObject>(exec, &JSHTMLOptionsCollectionConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSHTMLOptionsCollectionPrototypeTableValues[3] =
{
    { "add", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLOptionsCollectionPrototypeFunctionAdd), (intptr_t)2 THUNK_GENERATOR(0) },
    { "remove", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsHTMLOptionsCollectionPrototypeFunctionRemove), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSHTMLOptionsCollectionPrototypeTable = { 4, 3, JSHTMLOptionsCollectionPrototypeTableValues, 0 };
const ClassInfo JSHTMLOptionsCollectionPrototype::s_info = { "HTMLOptionsCollectionPrototype", 0, &JSHTMLOptionsCollectionPrototypeTable, 0 };

JSObject* JSHTMLOptionsCollectionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLOptionsCollection>(exec, globalObject);
}

bool JSHTMLOptionsCollectionPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLOptionsCollectionPrototypeTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollectionPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLOptionsCollectionPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLOptionsCollection::s_info = { "HTMLOptionsCollection", &JSHTMLCollection::s_info, &JSHTMLOptionsCollectionTable, 0 };

JSHTMLOptionsCollection::JSHTMLOptionsCollection(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLOptionsCollection> impl)
    : JSHTMLCollection(structure, globalObject, impl)
{
}

JSObject* JSHTMLOptionsCollection::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLOptionsCollectionPrototype(globalObject, JSHTMLOptionsCollectionPrototype::createStructure(JSHTMLCollectionPrototype::self(exec, globalObject)));
}

bool JSHTMLOptionsCollection::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLOptionsCollection, Base>(exec, &JSHTMLOptionsCollectionTable, this, propertyName, slot);
}

bool JSHTMLOptionsCollection::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLOptionsCollection, Base>(exec, &JSHTMLOptionsCollectionTable, this, propertyName, descriptor);
}

JSValue jsHTMLOptionsCollectionSelectedIndex(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    HTMLOptionsCollection* imp = static_cast<HTMLOptionsCollection*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->selectedIndex());
    return result;
}

JSValue jsHTMLOptionsCollectionLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    return castedThis->length(exec);
}

JSValue jsHTMLOptionsCollectionConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSHTMLOptionsCollection* domObject = static_cast<JSHTMLOptionsCollection*>(asObject(slotBase));
    return JSHTMLOptionsCollection::getConstructor(exec, domObject->globalObject());
}
void JSHTMLOptionsCollection::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok) {
        indexSetter(exec, index, value);
        return;
    }
    lookupPut<JSHTMLOptionsCollection, Base>(exec, propertyName, value, &JSHTMLOptionsCollectionTable, this, slot);
}

void JSHTMLOptionsCollection::put(ExecState* exec, unsigned propertyName, JSValue value)
{
    indexSetter(exec, propertyName, value);
    return;
}

void setJSHTMLOptionsCollectionSelectedIndex(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(thisObject);
    HTMLOptionsCollection* imp = static_cast<HTMLOptionsCollection*>(castedThis->impl());
    imp->setSelectedIndex(value.toInt32(exec));
}

void setJSHTMLOptionsCollectionLength(ExecState* exec, JSObject* thisObject, JSValue value)
{
    static_cast<JSHTMLOptionsCollection*>(thisObject)->setLength(exec, value);
}

JSValue JSHTMLOptionsCollection::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLOptionsCollectionConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsHTMLOptionsCollectionPrototypeFunctionAdd(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLOptionsCollection::s_info))
        return throwVMTypeError(exec);
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(thisValue));
    return JSValue::encode(castedThis->add(exec));
}

EncodedJSValue JSC_HOST_CALL jsHTMLOptionsCollectionPrototypeFunctionRemove(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSHTMLOptionsCollection::s_info))
        return throwVMTypeError(exec);
    JSHTMLOptionsCollection* castedThis = static_cast<JSHTMLOptionsCollection*>(asObject(thisValue));
    return JSValue::encode(castedThis->remove(exec));
}

HTMLOptionsCollection* toHTMLOptionsCollection(JSC::JSValue value)
{
    return value.inherits(&JSHTMLOptionsCollection::s_info) ? static_cast<JSHTMLOptionsCollection*>(asObject(value))->impl() : 0;
}

}
