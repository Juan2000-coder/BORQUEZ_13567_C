/**
 * @file    C5Server.h
 * @brief   Header file for the C5Server class and related classes.
 * 
 * @details This file declares the C5Server class and
 *          the XmlRpcServerMethods classes.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */
#ifndef _C5SERVER_H
#define _C5SERVER_H

#include "XmlRpc.h"
#include "C5NumberEngine.h"
#include "C5Number.h"
#include "C5ServerConnection.h"

#include <string>
#include <vector>

using namespace XmlRpc;

/**
 * @brief XML-RPC server method for user validation.
 *
 * This class extends XmlRpcServerMethod and implements the 'userValidate' method.
 * It interacts with the C5NumberEngine to perform user validation.
 */
class UserValidate : public XmlRpcServerMethod {
  public:
    UserValidate(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("userValidate", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server method for obtaining an integer.
 *
 * This class extends XmlRpcServerMethod and implements the 'getInt' method.
 * It interacts with the C5NumberEngine to retrieve an integer.
 */
class GetInt : public XmlRpcServerMethod {
  public:
    GetInt(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getInt", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server method for obtaining a real number.
 *
 * This class extends XmlRpcServerMethod and implements the 'getReal' method.
 * It interacts with the C5NumberEngine to retrieve a real number.
 */
class GetReal : public XmlRpcServerMethod {
  public:
    GetReal(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getReal", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server method for obtaining a previous number.
 *
 * This class extends XmlRpcServerMethod and implements the 'getNumberOld' method.
 * It interacts with the C5NumberEngine to retrieve a previous number.
 */
class GetNumberOld : public XmlRpcServerMethod {
  public:
    GetNumberOld(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getNumberOld", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server method for obtaining statistics.
 *
 * This class extends XmlRpcServerMethod and implements the 'getStat' method.
 * It interacts with the C5NumberEngine to retrieve statistics.
 */
class GetStat : public XmlRpcServerMethod {
  public:
    GetStat(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getStat", s), engine(_engine){};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server method for obtaining a list of numbers.
 *
 * This class extends XmlRpcServerMethod and implements the 'getNumberList' method.
 * It interacts with the C5NumberEngine to retrieve a list of numbers.
 */
class GetNumberList : public XmlRpcServerMethod {
  public:
    GetNumberList(XmlRpcServer* s, C5NumberEngine &_engine) : XmlRpcServerMethod("getNumberList", s), engine(_engine) {};
    void execute(XmlRpcValue& params, XmlRpcValue& result);
    std::string help() override;
  private:
    C5NumberEngine &engine;
};

/**
 * @brief XML-RPC server class for the C5 system.
 *
 * This class extends XmlRpcServer and provides methods to handle different XML-RPC requests.
 * It uses the C5NumberEngine for processing these requests.
 */
class C5Server: public XmlRpcServer {
  private:
    C5NumberEngine engine;
  public:
    //Constructor
    C5Server(): XmlRpcServer(), engine(), userValidate(this, engine), getInt(this, engine),
    getReal(this, engine), getNumberOld(this, engine), getStat(this, engine),
    getNumberList(this, engine) {};

    //bool userValidate(int userId);
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

    C5ServerConnection* createConnection(int socket) override;
};

#endif
