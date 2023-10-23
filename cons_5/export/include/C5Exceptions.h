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

class C5RequirementException: public std::exception{
  public:
    C5RequirementException(const char* _message): message(_message){};
    C5RequirementException(int exceptionCode);
    const char* what() const noexcept override{
      return message;
    };

  private:
    int exceptionCode;
    const char* message;
};

class C5NumberEngineException: public std::exception{
  public:
    C5NumberEngineException(const char* _message): message(_message){};
    C5NumberEngineException(int exceptionCode);
    const char* what() const noexcept override{
      return message;
    };
  private:
    int exceptionCode;
    const char* message;
};

class ServerExceptions: public std::exception{
  public:
    ServerExceptions(const char* _message): message(_message){};
    ServerExceptions(int exceptionCode);
    const char* what() const noexcept override{
      return message;
    };
  private:
    int exceptionCode;
    const char* message;
};
#endif