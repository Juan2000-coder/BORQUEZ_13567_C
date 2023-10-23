#ifndef _C5NUMBERENGINE_H
#define _C5NUMBERENGINE_H

#include "C5Requirement.h"
#include "C5Number.h"
#include "Stats.h"
#include <string>
#include <vector>

class C5NumberEngine{
  public:
    //constructor
    C5NumberEngine():validUsersFile("ValidUsers.txt"), requirementIndex(-1){};

    //methods
    bool userValidate(int userId);
    bool validationDone(int userId) const;
    
    int getInt(int userId, int bmin, int bmax);
    int getInt(int userId);
    double getReal(int userId, double bmin, double bmax);
    double getReal(int userId);
    template<typename Type> const C5Number<Type> &getNumberOld(int userId, int ordinal) const;//esto también podría ser un string
    Stats getStat(int userId) const;//esto puede ser una nueva clase de estadística
    const C5Requirement &getNumberList(int userid) const;//me parece que con ese tipo ocupa menos espacio

  private:
    std::vector<C5Requirement> requirements;
    std::string validUsersFile;
    int requirementIndex;
};
#include "C5NumberEngine.t.hpp"
#endif