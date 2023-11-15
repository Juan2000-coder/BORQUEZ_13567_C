#ifndef _C5EXCEPTIONS_H
#define _C5EXCEPTIONS_H

#include <exception>
#include <typeinfo>
#include <iostream>
#include <sstream>

/**
 * @brief Base class for C5 exceptions, derived from std::exception.
 */
class C5Exceptions: public std::exception {
  public:
    enum exceptionCodes { NOID };//(NOID) No Identified

    C5Exceptions(const char* _message): message(_message), code(static_cast<unsigned int>(NOID)){}
    C5Exceptions(): message("No identified"), code(static_cast<unsigned int>(NOID)){}

    const char* what() const noexcept override {
      return message;
    }

    /**
     * @brief Virtual method to provide information about the exception's origin.
     * @return A string indicating the origin of the exception.
     */
    virtual const char* where() const { return "base"; }

    /**
     * @brief Getter method to retrieve the exception code.
     * @return The exception code.
     */
    unsigned int getCode() const { return this->code; }

    /**
     * @brief Friend function to overload the output stream operator for printing exceptions.
     * @param os The output stream.
     * @param myExceptions The C5Exceptions object to be printed.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const C5Exceptions& myExceptions);

  protected:
    const char* message; // Exception message.
    unsigned int code;   // Exception code.
};

/**
 * @brief Derived class for C5 number-related exceptions.
 */
class C5NumberException: public C5Exceptions {
  public:
    enum exceptionCodes { LIMIT, TYPE };
    C5NumberException(exceptionCodes code);
    const char* where() const override { return "C5Number"; }
};

/**
 * @brief Derived class for C5 requirement-related exceptions.
 */
class C5RequirementException: public C5Exceptions {
  public:
    enum exceptionCodes { OUT_OF_RNG, NO_PREV_REQ, NO_PREV_REQ_TYPE };
    C5RequirementException(exceptionCodes code);
    const char* where() const override { return "C5Requirement"; }
};

/**
 * @brief Derived class for C5 number engine-related exceptions.
 */
class C5NumberEngineException: public C5Exceptions {
  public:
    enum exceptionCodes { AT_OPEN };
    C5NumberEngineException(exceptionCodes code);
    const char* where() const override { return "C5NumberEngine"; }
};

/**
 * @brief Derived class for server-related exceptions.
 */
class ServerException: public C5Exceptions {
  public:
    enum exceptionCodes { INV_SYN };
    ServerException(exceptionCodes code);
    const char* where() const override { return "Server"; }
};

#endif
