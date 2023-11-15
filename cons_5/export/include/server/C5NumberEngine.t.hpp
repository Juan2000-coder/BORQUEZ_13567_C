#include "C5NumberEngine.h"

template<typename Type>
const C5Number<Type> &C5NumberEngine::getNumberOld(int ordinal)const{
    //Throws a bad_access exception in case the Type is not the correct type.
    const C5Requirement& requirement = this->requirements.at(this->requirementIndex);
    return requirement.getNumber<Type>(ordinal);
}