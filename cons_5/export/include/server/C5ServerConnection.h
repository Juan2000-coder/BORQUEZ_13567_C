#ifndef _C5SERVERCONNECTION_H
#define _C5SERVERCONNECTION_H

#include "XmlRpcServerConnection.h"

using namespace XmlRpc;

/**
 * @brief Custom server connection class.
 *
 * This class extends XmlRpcServerConnection to overrides the executeRequest method.
 */
class C5ServerConnection : public XmlRpcServerConnection {
    using XmlRpcServerConnection::XmlRpcServerConnection; // Use Base class constructors.

    /**
     * @brief Overrides the execution of an XML-RPC request.
     *
     * It overrides the base class method to provide custom exception
     * handling specific to C5.
     */
    void executeRequest() override;
};

#endif
