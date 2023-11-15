/**
 * @file    C5ServerConnection.h
 * @brief   Header file for the C5ServerConnection class.
 * 
 * @details This file declares the C5Server class.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */
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
