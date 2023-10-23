#include "C5NumberEngine.h"

template<typename Type>
const C5Number<Type> &C5NumberEngine::getNumberOld(int userId, int ordinal)const{
    if (this->validationDone(userId)){
        //Lanza una excepción de bad_access en caso de que no sea el tipo correcto
        auto requirement = this->requirements.at(this->requirementIndex);
        return requirement.getNumber<Type>(ordinal);
    }
}