#ifndef _C5EXCEPTIONS_H
#define _C5EXCEPTIONS_H

#include <exception>

class C5NumberException: public std::exception{
  public:
    C5NumberException(const char* _message): message(_message){};
    C5NumberException(int exceptionCode);

    const char* what() const noexcept override{
      return message;
    }

  private:
    const char* message;
    int exceptionCode;
};

class C5ReqirementException: public std::exception{
  public:
    C5ReqirementException(const char* _message): message(_message){};
    C5ReqirementException(int exceptionCode);
    const char* what() const noexcept override{
      return message;
    };

  private:
    int exceptionCode;
    const char* message;
};

#endif