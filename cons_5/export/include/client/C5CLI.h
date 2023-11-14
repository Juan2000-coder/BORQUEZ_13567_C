#ifndef _C5CLI_H
#define _C5CLI_h

#include "XmlRpc.h"
#include "C5User.h"
#include "C5Client.h"
#include <map>
#include <tuple>
#include <string>

using namespace XmlRpc;
using namespace std;

class C5CLI{
    public:
        bool loop(C5Client& client, C5User& user) const;
        bool parseRequest(string& method, XmlRpcValue& args, string& line, int id) const;
        bool validateArgs(string& method, XmlRpcValue& args) const;
        string menu() const;
        string parseResponse(string& method, XmlRpcValue& result) const;
        string parseFaultResponse(string& method, XmlRpcValue& result) const;
        string prompt()const;
    private:
        static const map<string, string> methods;
};
#endif