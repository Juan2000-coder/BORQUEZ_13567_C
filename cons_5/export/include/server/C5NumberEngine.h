#ifndef _C5NUMBERENGINE_H
#define _C5NUMBERENGINE_H

#include "C5Requirement.h"
#include "C5Number.h"
#include "Stats.h"
#include <string>
#include <vector>
#include <fstream>


class C5NumberEngine{
  public:
    //constructor
    C5NumberEngine();

    //methods
    bool userValidate(int userId);
    
    int getInt(int bmin, int bmax);
    int getInt();
    double getReal(double bmin, double bmax);
    double getReal();
    template<typename Type> const C5Number<Type> &getNumberOld(int ordinal) const;//esto también podría ser un string
    Stats getStat() const;//esto puede ser una nueva clase de estadística
    const C5Requirement &getNumberList() const;//me parece que con ese tipo ocupa menos espacio

  private:
    std::vector<C5Requirement> requirements;
    std::string validUsersFile;
    int requirementIndex;
};
#include "C5NumberEngine.t.hpp"
#endif