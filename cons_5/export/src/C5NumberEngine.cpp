#include "C5NumberEngine.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <utility>//ver después si realmente hace falta su inclusión

bool C5NumberEngine::userValidate(int userId){
    //Primero verifica en la lista de requerimientos
    int index = 0;
    for(C5Requirement &requirement: this->requirements){
        if (requirement.getUserId() == userId){
            this->requirementIndex = index;
            return true;
        }
        index++;
    }

    //Luego verifica en el archivo
    std::ifstream validUsers(this->validUsersFile);
    if (!validUsers.is_open()){
        throw C5NumberEngineException(1);
    }
    std::string idRequest = std::to_string(userId);
    std::string id;

    while (std::getline(validUsers, id)){
        if (id == idRequest){
            /*Si es valido también creamos un request correspondiente*/
            this->requirements.push_back(C5Requirement(userId));
            this->requirementIndex = this->requirements.size() - 1;
            return true;
        }
    }
    return false;
}

/*La validación se hace llamando al método anterior. Se encarga el engine.*/
/*La siguiente verifica en cada función que la validación se haya realizado.*/
bool C5NumberEngine::validationDone(int userId)const{
    if(this->requirements.at(this->requirementIndex).getUserId() != userId){
        return false;
    }
    return true;
}

int C5NumberEngine::getInt(int userId, int bmin, int bmax){
    if (this->validationDone(userId)){
        //La verificación lanza una excepción en caso de que no se haya realizado.
        auto requirement = this->requirements.at(this->requirementIndex);
        requirement.appendNumber<int>(bmin, bmax);
        return requirement.getNumber<int>().getValue();
    }
    else{
        throw C5NumberEngineException(2);
    }
}

int C5NumberEngine::getInt(int userId){
    if (this->validationDone(userId)){
        auto requirement = this->requirements.at(this->requirementIndex);
        requirement.appendNumber<int>();
        return requirement.getNumber<int>().getValue();
    }
    else{
        throw C5NumberEngineException(2);
    }
}

double C5NumberEngine::getReal(int userId, double bmin, double bmax){
    if (this->validationDone(userId)){
        //La verificación lanza una excepción en caso de que no se haya realizado.
        auto requirement = this->requirements.at(this->requirementIndex);
        requirement.appendNumber<double>(bmin, bmax);
        return requirement.getNumber<double>().getValue();
    }
    else{
        throw C5NumberEngineException(2);
    }
}
double C5NumberEngine::getReal(int userId){
    if (this->validationDone(userId)){
        //La verificación lanza una excepción en caso de que no se haya realizado.
        auto requirement = this->requirements.at(this->requirementIndex);
        requirement.appendNumber<double>();
        return requirement.getNumber<double>().getValue();
    }
    else{
        throw C5NumberEngineException(2);
    }
}
Stats C5NumberEngine::getStat(int userId) const{
    if (this->validationDone(userId)){
        //La verificación lanza una excepción en caso de que no se haya realizado.
        auto requirement = this->requirements.at(this->requirementIndex);
        return requirement.getStats();
    }
    else{
        throw C5NumberEngineException(2);
    }
}
//A la mierda, devolvemos el vector de variants y a la chota.
const C5Requirement& C5NumberEngine::getNumberList(int userId) const{
    if (this->validationDone(userId)){
        //La verificación lanza una excepción en caso de que no se haya realizado.
        return this->requirements.at(this->requirementIndex);
    }
    else{
        throw C5NumberEngineException(2);
    }
}
