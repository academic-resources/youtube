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

#if ENABLE(WEB_SOCKETS)

#include "JSWebSocket.h"

#include "Event.h"
#include "EventListener.h"
#include "JSEvent.h"
#include "JSEventListener.h"
#include "KURL.h"
#include "RegisteredEventListener.h"
#include "WebSocket.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSWebSocket);

/* Hash table */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebSocketTableValues[9] =
{
    { "URL", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketURL), (intptr_t)0 THUNK_GENERATOR(0) },
    { "readyState", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketReadyState), (intptr_t)0 THUNK_GENERATOR(0) },
    { "bufferedAmount", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketBufferedAmount), (intptr_t)0 THUNK_GENERATOR(0) },
    { "onopen", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOnopen), (intptr_t)setJSWebSocketOnopen THUNK_GENERATOR(0) },
    { "onmessage", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOnmessage), (intptr_t)setJSWebSocketOnmessage THUNK_GENERATOR(0) },
    { "onerror", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOnerror), (intptr_t)setJSWebSocketOnerror THUNK_GENERATOR(0) },
    { "onclose", DontDelete, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOnclose), (intptr_t)setJSWebSocketOnclose THUNK_GENERATOR(0) },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketConstructor), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebSocketTable = { 17, 15, JSWebSocketTableValues, 0 };
/* Hash table for constructor */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebSocketConstructorTableValues[4] =
{
    { "CONNECTING", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketCONNECTING), (intptr_t)0 THUNK_GENERATOR(0) },
    { "OPEN", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOPEN), (intptr_t)0 THUNK_GENERATOR(0) },
    { "CLOSED", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketCLOSED), (intptr_t)0 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebSocketConstructorTable = { 8, 7, JSWebSocketConstructorTableValues, 0 };

COMPILE_ASSERT(0 == WebSocket::CONNECTING, WebSocketEnumCONNECTINGIsWrongUseDontCheckEnums);
COMPILE_ASSERT(1 == WebSocket::OPEN, WebSocketEnumOPENIsWrongUseDontCheckEnums);
COMPILE_ASSERT(2 == WebSocket::CLOSED, WebSocketEnumCLOSEDIsWrongUseDontCheckEnums);

const ClassInfo JSWebSocketConstructor::s_info = { "WebSocketConstructor", 0, &JSWebSocketConstructorTable, 0 };

JSWebSocketConstructor::JSWebSocketConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(JSWebSocketConstructor::createStructure(globalObject->objectPrototype()), globalObject)
{
    putDirect(exec->propertyNames().prototype, JSWebSocketPrototype::self(exec, globalObject), DontDelete | ReadOnly);
    putDirect(exec->propertyNames().length, jsNumber(exec, 1), ReadOnly | DontDelete | DontEnum);
}

bool JSWebSocketConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWebSocketConstructor, DOMObject>(exec, &JSWebSocketConstructorTable, this, propertyName, slot);
}

bool JSWebSocketConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWebSocketConstructor, DOMObject>(exec, &JSWebSocketConstructorTable, this, propertyName, descriptor);
}

ConstructType JSWebSocketConstructor::getConstructData(ConstructData& constructData)
{
    constructData.native.function = constructJSWebSocket;
    return ConstructTypeHost;
}

/* Hash table for prototype */
#if ENABLE(JIT)
#define THUNK_GENERATOR(generator) , generator
#else
#define THUNK_GENERATOR(generator)
#endif

static const HashTableValue JSWebSocketPrototypeTableValues[9] =
{
    { "CONNECTING", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketCONNECTING), (intptr_t)0 THUNK_GENERATOR(0) },
    { "OPEN", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketOPEN), (intptr_t)0 THUNK_GENERATOR(0) },
    { "CLOSED", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsWebSocketCLOSED), (intptr_t)0 THUNK_GENERATOR(0) },
    { "send", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsWebSocketPrototypeFunctionSend), (intptr_t)1 THUNK_GENERATOR(0) },
    { "close", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsWebSocketPrototypeFunctionClose), (intptr_t)0 THUNK_GENERATOR(0) },
    { "addEventListener", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsWebSocketPrototypeFunctionAddEventListener), (intptr_t)3 THUNK_GENERATOR(0) },
    { "removeEventListener", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsWebSocketPrototypeFunctionRemoveEventListener), (intptr_t)3 THUNK_GENERATOR(0) },
    { "dispatchEvent", DontDelete | Function, (intptr_t)static_cast<NativeFunction>(jsWebSocketPrototypeFunctionDispatchEvent), (intptr_t)1 THUNK_GENERATOR(0) },
    { 0, 0, 0, 0 THUNK_GENERATOR(0) }
};

#undef THUNK_GENERATOR
static JSC_CONST_HASHTABLE HashTable JSWebSocketPrototypeTable = { 17, 15, JSWebSocketPrototypeTableValues, 0 };
static const HashTable* getJSWebSocketPrototypeTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSWebSocketPrototypeTable);
}
const ClassInfo JSWebSocketPrototype::s_info = { "WebSocketPrototype", 0, 0, getJSWebSocketPrototypeTable };

JSObject* JSWebSocketPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSWebSocket>(exec, globalObject);
}

bool JSWebSocketPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSWebSocketPrototype, JSObject>(exec, getJSWebSocketPrototypeTable(exec), this, propertyName, slot);
}

bool JSWebSocketPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSWebSocketPrototype, JSObject>(exec, getJSWebSocketPrototypeTable(exec), this, propertyName, descriptor);
}

static const HashTable* getJSWebSocketTable(ExecState* exec)
{
    return getHashTableForGlobalData(exec->globalData(), &JSWebSocketTable);
}
const ClassInfo JSWebSocket::s_info = { "WebSocket", 0, 0, getJSWebSocketTable };

JSWebSocket::JSWebSocket(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<WebSocket> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSWebSocket::~JSWebSocket()
{
    impl()->invalidateJSEventListeners(this);
    forgetDOMObject(this, impl());
}

void JSWebSocket::markChildren(MarkStack& markStack)
{
    Base::markChildren(markStack);
    impl()->markJSEventListeners(markStack);
}

JSObject* JSWebSocket::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSWebSocketPrototype(globalObject, JSWebSocketPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSWebSocket::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSWebSocket, Base>(exec, getJSWebSocketTable(exec), this, propertyName, slot);
}

bool JSWebSocket::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSWebSocket, Base>(exec, getJSWebSocketTable(exec), this, propertyName, descriptor);
}

JSValue jsWebSocketURL(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    JSValue result = jsString(exec, imp->url());
    return result;
}

JSValue jsWebSocketReadyState(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->readyState());
    return result;
}

JSValue jsWebSocketBufferedAmount(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->bufferedAmount());
    return result;
}

JSValue jsWebSocketOnopen(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    if (EventListener* listener = imp->onopen()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsWebSocketOnmessage(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    if (EventListener* listener = imp->onmessage()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsWebSocketOnerror(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    if (EventListener* listener = imp->onerror()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsWebSocketOnclose(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    if (EventListener* listener = imp->onclose()) {
        if (const JSEventListener* jsListener = JSEventListener::cast(listener)) {
            if (JSObject* jsFunction = jsListener->jsFunction(imp->scriptExecutionContext()))
                return jsFunction;
        }
    }
    return jsNull();
}

JSValue jsWebSocketConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSWebSocket* domObject = static_cast<JSWebSocket*>(asObject(slotBase));
    return JSWebSocket::getConstructor(exec, domObject->globalObject());
}
void JSWebSocket::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSWebSocket, Base>(exec, propertyName, value, getJSWebSocketTable(exec), this, slot);
}

void setJSWebSocketOnopen(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(static_cast<JSWebSocket*>(thisObject)->impl());
    imp->setOnopen(createJSAttributeEventListener(exec, value, thisObject));
}

void setJSWebSocketOnmessage(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(static_cast<JSWebSocket*>(thisObject)->impl());
    imp->setOnmessage(createJSAttributeEventListener(exec, value, thisObject));
}

void setJSWebSocketOnerror(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(static_cast<JSWebSocket*>(thisObject)->impl());
    imp->setOnerror(createJSAttributeEventListener(exec, value, thisObject));
}

void setJSWebSocketOnclose(ExecState* exec, JSObject* thisObject, JSValue value)
{
    UNUSED_PARAM(exec);
    WebSocket* imp = static_cast<WebSocket*>(static_cast<JSWebSocket*>(thisObject)->impl());
    imp->setOnclose(createJSAttributeEventListener(exec, value, thisObject));
}

JSValue JSWebSocket::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSWebSocketConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsWebSocketPrototypeFunctionSend(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSWebSocket::s_info))
        return throwVMTypeError(exec);
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(thisValue));
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    if (exec->argumentCount() < 1)
        return JSValue::encode(jsUndefined());
    ExceptionCode ec = 0;
    const String& data = ustringToString(exec->argument(0).toString(exec));


    JSC::JSValue result = jsBoolean(imp->send(data, ec));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

EncodedJSValue JSC_HOST_CALL jsWebSocketPrototypeFunctionClose(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSWebSocket::s_info))
        return throwVMTypeError(exec);
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(thisValue));
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());

    imp->close();
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsWebSocketPrototypeFunctionAddEventListener(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSWebSocket::s_info))
        return throwVMTypeError(exec);
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(thisValue));
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    JSValue listener = exec->argument(1);
    if (!listener.isObject())
        return JSValue::encode(jsUndefined());
    imp->addEventListener(ustringToAtomicString(exec->argument(0).toString(exec)), JSEventListener::create(asObject(listener), castedThis, false, currentWorld(exec)), exec->argument(2).toBoolean(exec));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsWebSocketPrototypeFunctionRemoveEventListener(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSWebSocket::s_info))
        return throwVMTypeError(exec);
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(thisValue));
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    JSValue listener = exec->argument(1);
    if (!listener.isObject())
        return JSValue::encode(jsUndefined());
    imp->removeEventListener(ustringToAtomicString(exec->argument(0).toString(exec)), JSEventListener::create(asObject(listener), castedThis, false, currentWorld(exec)).get(), exec->argument(2).toBoolean(exec));
    return JSValue::encode(jsUndefined());
}

EncodedJSValue JSC_HOST_CALL jsWebSocketPrototypeFunctionDispatchEvent(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    if (!thisValue.inherits(&JSWebSocket::s_info))
        return throwVMTypeError(exec);
    JSWebSocket* castedThis = static_cast<JSWebSocket*>(asObject(thisValue));
    WebSocket* imp = static_cast<WebSocket*>(castedThis->impl());
    ExceptionCode ec = 0;
    Event* evt = toEvent(exec->argument(0));


    JSC::JSValue result = jsBoolean(imp->dispatchEvent(evt, ec));
    setDOMException(exec, ec);
    return JSValue::encode(result);
}

// Constant getters

JSValue jsWebSocketCONNECTING(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(0));
}

JSValue jsWebSocketOPEN(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsWebSocketCLOSED(ExecState* exec, JSValue, const Identifier&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, WebSocket* object)
{
    return getDOMObjectWrapper<JSWebSocket>(exec, globalObject, object);
}
WebSocket* toWebSocket(JSC::JSValue value)
{
    return value.inherits(&JSWebSocket::s_info) ? static_cast<JSWebSocket*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(WEB_SOCKETS)
