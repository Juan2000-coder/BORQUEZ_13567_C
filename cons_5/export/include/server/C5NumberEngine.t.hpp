#include "C5NumberEngine.h"
#include <iostream>
template<typename Type>
const C5Number<Type> &C5NumberEngine::getNumberOld(int ordinal)const{
    //Lanza una excepción de bad_access en caso de que no sea el tipo correcto
    const C5Requirement& requirement = this->requirements.at(this->requirementIndex);
    return requirement.getNumber<Type>(ordinal);
}