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

#ifndef JSNodeFilter_h
#define JSNodeFilter_h

#include "JSDOMBinding.h"
#include <runtime/JSGlobalObject.h>
#include <runtime/JSObjectWithGlobalObject.h>
#include <runtime/ObjectPrototype.h>

namespace WebCore {

class NodeFilter;

class JSNodeFilter : public DOMObjectWithGlobalPointer {
    typedef DOMObjectWithGlobalPointer Base;
public:
    JSNodeFilter(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<NodeFilter>);
    virtual ~JSNodeFilter();
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), AnonymousSlotCount);
    }

    virtual void markChildren(JSC::MarkStack&);

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);
    NodeFilter* impl() const { return m_impl.get(); }

private:
    RefPtr<NodeFilter> m_impl;
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, NodeFilter*);
PassRefPtr<NodeFilter> toNodeFilter(JSC::JSValue);

class JSNodeFilterPrototype : public JSC::JSObjectWithGlobalObject {
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
    JSNodeFilterPrototype(JSC::JSGlobalObject* globalObject, NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObjectWithGlobalObject(globalObject, structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::EncodedJSValue JSC_HOST_CALL jsNodeFilterPrototypeFunctionAcceptNode(JSC::ExecState*);
// Attributes

JSC::JSValue jsNodeFilterConstructor(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
// Constants

JSC::JSValue jsNodeFilterFILTER_ACCEPT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterFILTER_REJECT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterFILTER_SKIP(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_ALL(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_ELEMENT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_ATTRIBUTE(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_TEXT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_CDATA_SECTION(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_ENTITY_REFERENCE(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_ENTITY(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_PROCESSING_INSTRUCTION(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_COMMENT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT_TYPE(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_DOCUMENT_FRAGMENT(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);
JSC::JSValue jsNodeFilterSHOW_NOTATION(JSC::ExecState*, JSC::JSValue, const JSC::Identifier&);

} // namespace WebCore

#endif
