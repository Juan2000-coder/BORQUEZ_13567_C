#include "C5ServerConnection.h"
#include "XmlRpcUtil.h"
#include "XmlRpcException.h"
#include "C5Exceptions.h"

using namespace XmlRpc;

void C5ServerConnection::executeRequest(){
    XmlRpcValue params, resultValue;
    std::string methodName = parseRequest(params);
    XmlRpcUtil::log(2, "XmlRpcServerConnection::executeRequest: server calling method '%s'",
                    methodName.c_str());
    try { // In this block both XmlRpc library exception and custom exceptions are rise.
        if (! executeMethod(methodName, params, resultValue) &&
            ! executeMulticall(methodName, params, resultValue))
            generateFaultResponse(methodName + ": unknown method name");
        else
            generateResponse(resultValue.toXml());
    }
    catch(const C5Exceptions &e){  // Catches custom exceptions.
        std::cerr << e;            // Outputs the exception object to cerr.
        resultValue = e.what();    // Custom exception message.
        generateFaultResponse(e.what(), e.getCode()); // Fault response.
    }
    catch (const XmlRpcException& fault) { // XmlRpc library exception.
        XmlRpcUtil::log(2, "XmlRpcServerConnection::executeRequest: fault %s.",
                        fault.getMessage().c_str()); 
        generateFaultResponse(fault.getMessage(), fault.getCode());
    }
}