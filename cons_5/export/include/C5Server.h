#ifndef _C5SERVER_H
#define _C5SERVER_H

#include "XmlRpc.h"
#include "C5NumberEngine.h"

#include <string>
#include <vector>

using namespace XmlRpc;

class UserValidate : public XmlRpcServerMethod{
  public:
    UserValidate(XmlRpcServer* s) : XmlRpcServerMethod("userValidate", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class GetInt : public XmlRpcServerMethod{
  public:
    GetInt(XmlRpcServer* s) : XmlRpcServerMethod("getInt", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class GetReal : public XmlRpcServerMethod{
  public:
    GetReal(XmlRpcServer* s) : XmlRpcServerMethod("getReal", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class GetNumberOld : public XmlRpcServerMethod{
  public:
    GetNumberOld(XmlRpcServer* s) : XmlRpcServerMethod("getNumberOld", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class GetStat : public XmlRpcServerMethod{
  public:
    GetStat(XmlRpcServer* s) : XmlRpcServerMethod("getStat", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class GetNumberList : public XmlRpcServerMethod{
  public:
    GetNumberList(XmlRpcServer* s) : XmlRpcServerMethod("getNumberList", s) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
};

class C5Server: public XmlRpcServer{
  public:
    //Constructor
    C5Server():userValidate(this), getInt(this), getReal(this), getNumberOld(this), getStat(this),
    getNumberList(this), engine(){};

    //bool userValidate(int userdId);
    UserValidate userValidate;

    //int getInt(int bmin, int bmax);
    //int getInt();
    GetInt getInt;

    //double getReal(double bmin, double bmax);
    //double getReal();
    GetReal getReal;

    //getNumberOld(int ordinal);
    GetNumberOld getNumberOld;

    //getStat(int userId);
    GetStat getStat;

    //getNumberList(int userid);
    GetNumberList getNumberList;

  private:
    C5NumberEngine engine;
};
#endif