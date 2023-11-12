#ifndef _C5EXCEPTIONS_H
#define _C5EXCEPTIONS_H

#include <exception>
#include <typeinfo>

class C5Exceptions: public::std::exception{
  public:
    C5Exceptions(const char* _message): message(_message){};
    C5Exceptions():message("No dentificada"){}
    const char* what() const noexcept override{
      return message;
    }
    virtual const char* where() const;

  protected:
    const char* message;
};

class C5NumberException: public C5Exceptions{
  public:
    enum exceptionCodes {LIMIT, TYPE};
    C5NumberException(exceptionCodes code);
    const char* where() const override {return "C5Number";}
};

class C5RequirementException: public C5Exceptions{
  public:
    enum exceptionCodes {OUT_OF_RNG, NO_PREV_REQ, NO_PREV_REQ_TYPE};
    C5RequirementException(exceptionCodes code);
    const char* where() const override {return "C5Requirement";}
};

class C5NumberEngineException: public C5Exceptions{
  public:
    enum exceptionCodes {AT_OPEN};
    C5NumberEngineException(exceptionCodes code);
    const char* where() const override{return "C5NumberEngine";}
};

class ServerExceptions: public C5Exceptions{
  public:
    enum exceptionCodes {INV_SYN};
    ServerExceptions(exceptionCodes code);
    const char* where() const override{return "Server";}
};
#endif