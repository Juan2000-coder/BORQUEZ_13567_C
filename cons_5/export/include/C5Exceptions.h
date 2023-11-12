#ifndef _C5EXCEPTIONS_H
#define _C5EXCEPTIONS_H

#include <exception>
#include <typeinfo>
#include <iostream>
#include <sstream>

class C5Exceptions: public std::exception{
  public:
    enum exceptionCodes{NOID};
    C5Exceptions(const char* _message): message(_message), code(static_cast<unsigned int>(NOID)){}
    C5Exceptions():message("No dentificada"), code(static_cast<unsigned int>(NOID)){}
    const char* what() const noexcept override{
      return message;
    }
    virtual const char* where() const{return "base";}
    unsigned int getCode() const {return this->code;}
    friend std::ostream& operator<<(std::ostream& os, const C5Exceptions& myExceptions);

  protected:
    const char* message;
    unsigned int code;
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

class ServerException: public C5Exceptions{
  public:
    enum exceptionCodes {INV_SYN};
    ServerException(exceptionCodes code);
    const char* where() const override{return "Server";}
};
#endif