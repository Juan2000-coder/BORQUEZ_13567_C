#ifndef _C5SERVER_H
#define _C5SERVER_H

#include "XmlRpc.h"
#include "C5NumberEngine.h"
#include "C5Number.h"

#include <string>
#include <vector>

using namespace XmlRpc;

class UserValidate : public XmlRpcServerMethod{
  public:
    UserValidate(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("userValidate", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class GetInt : public XmlRpcServerMethod{
  public:
    GetInt(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getInt", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class GetReal : public XmlRpcServerMethod{
  public:
    GetReal(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getReal", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class GetNumberOld : public XmlRpcServerMethod{
  public:
    GetNumberOld(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getNumberOld", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class GetStat : public XmlRpcServerMethod{
  public:
    GetStat(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getStat", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class GetNumberList : public XmlRpcServerMethod{
  public:
    GetNumberList(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getNumberList", s), engine(_engine) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
  private:
    C5NumberEngine &engine;
};

class C5Server: public XmlRpcServer{
  public:
    //Constructor
    C5Server():XmlRpcServer(), engine(), userValidate(this, engine), getInt(this, engine),
    getReal(this, engine), getNumberOld(this, engine), getStat(this, engine),
    getNumberList(this, engine) {};

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