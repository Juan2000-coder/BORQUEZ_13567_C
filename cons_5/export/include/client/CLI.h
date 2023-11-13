#ifndef _CLI_H
#define _CLI_h

#include "XmlRpc.h"
#include "User.h"
#include <map>
#include <tuple>
#include <string>

using namespace XmlRpc;
using namespace std;

class CLI{
    public:
        bool loop(XmlRpcClient& client, User& user) const;
        void menu() const;
        bool parse(string& method, XmlRpcValue& args, string& line, int id) const;
        bool validateArgs(string& method, XmlRpcValue& args) const;
        void prompt()const;
    private:
        static const map<string, string> methods;
};
#endif