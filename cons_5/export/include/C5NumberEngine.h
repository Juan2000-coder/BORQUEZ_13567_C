#ifndef _C5NUMBERENGINE_H
#define _C5NUMBERENGINE_H

#include "C5Requirement.h"
#include "C5Number.h"
#include <string>
#include <vector>

class C5NumberEngine{
  public:
    //constructor
    C5NumberEngine():validUsersFile("ValidUsers.txt"){};

    //methods
    bool userValidate(int userdId);
    int getInt(int bmin, int bmax);
    int getInt();
    int getInt(int bmin, int bmax);
    int getInt();
    double getReal(double bmin, double bmax);
    double getReal();
    template<typename Type> C5Number<Type> getNumberOld(int ordinal);//esto también podría ser un string
    std::string getStat(int userId);//esto puede ser una nueva clase de estadística
    std::string getNumberList(int userid);//me parece que con ese tipo ocupa menos espacio

  private:
    std::vector<C5Requirement> requirements;
    std::string validUsersFile;
};
#endif