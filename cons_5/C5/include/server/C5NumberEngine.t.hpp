/**
 * @file    C5NumberEngine.t.hpp
 * @brief   Template implementation file for C5NumberEngine class member functions.
 * 
 * @details This file contains the template implementation for the C5NumberEngine class's
 *          getNumberOld member function, which retrieves an old C5Number object based on its ordinal.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */
#include "C5NumberEngine.h"

template<typename Type>
const C5Number<Type> &C5NumberEngine::getNumberOld(int ordinal)const{
    //Throws a bad_access exception in case the Type is not the correct type.
    const C5Requirement& requirement = this->requirements.at(this->requirementIndex);
    return requirement.getNumber<Type>(ordinal);
}