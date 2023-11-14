#include "C5ServerConnection.h"
#include "XmlRpcUtil.h"
#include "XmlRpcException.h"
#include "C5Exceptions.h"
#include <iostream>

using namespace XmlRpc;

void C5ServerConnection::executeRequest(){
    XmlRpcValue params, resultValue;
    std::string methodName = parseRequest(params);
    XmlRpcUtil::log(2, "XmlRpcServerConnection::executeRequest: server calling method '%s'",
                    methodName.c_str());
    try {
        if (! executeMethod(methodName, params, resultValue) &&
            ! executeMulticall(methodName, params, resultValue))
            generateFaultResponse(methodName + ": unknown method name");
        else
            generateResponse(resultValue.toXml());
    }
    catch(const C5Exceptions &e){
        std::cerr << e;
        resultValue = e.what();
        generateFaultResponse(e.what(), e.getCode());
    }
    catch (const XmlRpcException& fault) {
        XmlRpcUtil::log(2, "XmlRpcServerConnection::executeRequest: fault %s.",
                        fault.getMessage().c_str()); 
        generateFaultResponse(fault.getMessage(), fault.getCode());
    }
}