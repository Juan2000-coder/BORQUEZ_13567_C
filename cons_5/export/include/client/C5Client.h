#ifndef _C5CLIENT_H
#define _C5CLIENT_H
#include "XmlRpc.h"
#include <string>
#include <fstream>

using namespace XmlRpc;

class C5Client: public XmlRpcClient{
    public:
        using XmlRpcClient::XmlRpcClient;
        bool parseResponse(XmlRpcValue& result) override;
        void setXmlFile(std::string file);
        bool dumToFile(std::string);
    private:
        std::string XmlFile;
};
#endif