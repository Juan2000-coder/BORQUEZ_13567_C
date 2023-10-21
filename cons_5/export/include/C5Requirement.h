#ifndef _C5REQUIREMENT_H
#define _C5REQUIREMENT_H

#include "C5Number.h"
#include <vector>
#include <variant>
#include <string>

class C5Requirement {
  public:
    //constructor
    C5Requirement();
    C5Requirement(int userId);

    //setters
    void setUserId(int id);
    template <typename Type> void appendNumber();
    template <typename Type> void appendNumber(Type bmin, Type bmax);

    //getters
    int getUserId() const;
    long getInitialTime() const;

    template<typename Type> const C5Number<Type> &getNumber(int ordinal) const;
    template<typename Type> const C5Number<Type> &getNumber() const;
    template<typename Type> const C5Number<Type> &getRecent() const;

  private:
    int userId;
    long initialTime;
    std::vector<std::variant<C5Number<int>, C5Number<double>>>numbers;
};
#include "C5Requirement.t.hpp"
#endif