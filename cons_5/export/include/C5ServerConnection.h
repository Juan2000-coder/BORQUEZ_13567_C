#ifndef _C5SERVERCONNECTION_H
#define _C5SERVERCONNECTION_H
#include "XmlRpcServerConnection.h"

using namespace XmlRpc;
class C5ServerConnection: public XmlRpcServerConnection{
    using XmlRpcServerConnection::XmlRpcServerConnection;
    void executeRequest() override;
};

#endif