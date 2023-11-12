#ifndef _C5REQUIREMENT_H
#define _C5REQUIREMENT_H

#include "C5Number.h"
#include "Stats.h"
#include <vector>
#include <variant>
#include <string>
#include <chrono>

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
    std::chrono::_V2::system_clock::time_point getInitialTime() const;
    long getCurrentStamp() const;
    int getNumbersCount() const;
    Stats getStats() const;

    template<typename Type> const C5Number<Type> &getNumber(int ordinal) const;
    template<typename Type> const C5Number<Type> &getNumber() const;
    template<typename Type> const C5Number<Type> &getRecent() const;

  private:
    int userId;
    std::chrono::_V2::system_clock::time_point initialTime;
    std::vector<std::variant<C5Number<int>, C5Number<double>>>numbers;
};
#include "C5Requirement.t.hpp"
#endif