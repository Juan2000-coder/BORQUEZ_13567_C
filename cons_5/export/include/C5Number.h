#ifndef _C5NUMBER_H
#define _C5NUMBER_H

#include <string>

template <class Type> class C5Number {
  public:
    C5Number(Type bmin, Type bmax, long time);

    void setOrdinal(int ordinal);

    int getOrdinal() const;
    std::string getType() const;
    Type getValue() const;
    Type getBmin() const;
    Type getBmax() const;
    long getTime() const;

  private:
    int ordinal;
    std::string type;
    Type value;
    Type bmin;
    Type bmax;
    long time;
};
#include "C5Number.t.hpp"
#endif