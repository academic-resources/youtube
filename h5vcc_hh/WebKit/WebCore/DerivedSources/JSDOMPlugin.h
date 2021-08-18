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

#ifndef JSDOMPlugin_h
#define JSDOMPlugin_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class DOMPlugin;

class JSDOMPlugin : public DOMObjectWithGlobalPointer {
    typedef DOMObjectWithGlobalPointer Base;
public:
    JSDOMPlugin(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<DOMPlugin>);
    virtual ~JSDOMPlugin();
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual bool getOwnPropertySlot(JSC::ExecState*, unsigned propertyName, JSC::PropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }

    virtual void getOwnPropertyNames(JSC::ExecState*, JSC::PropertyNameArray&, JSC::EnumerationMode mode = JSC::ExcludeDontEnumProperties);
    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
    DOMPlugin* impl() const { return m_impl.get(); }

private:
    RefPtr<DOMPlugin> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesGetPropertyNames | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
    static JSC::JSValue indexGetter(JSC::ExecState*, JSC::JSValue, unsigned);
private:
    static bool canGetItemsForName(JSC::ExecState*, DOMPlugin*, const JSC::Identifier&);
    static JSC::JSValue nameGetter(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, DOMPlugin*);
DOMPlugin* toDOMPlugin(JSC::JSValue);

class JSDOMPluginPrototype : public JSC::JSObjectWithGlobalObject {
    typedef JSC::JSObjectWithGlobalObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }
    JSDOMPluginPrototype(JSC::JSGlobalObject* globalObject, NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObjectWithGlobalObject(globalObject, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsDOMPluginPrototypeFunctionItem(JSC::ExecState*);
JSC::EncodedJSValue JSC_HOST_CALL jsDOMPluginPrototypeFunctionNamedItem(JSC::ExecState*);
// Attributes

JSC::JSValue jsDOMPluginName(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMPluginFilename(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMPluginDescription(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMPluginLength(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsDOMPluginConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif
