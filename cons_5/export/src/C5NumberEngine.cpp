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


int C5NumberEngine::getInt(int bmin, int bmax){
    //La verificación lanza una excepción en caso de que no se haya realizado.
    auto requirement = this->requirements.at(this->requirementIndex);
    requirement.appendNumber<int>(bmin, bmax);
    return requirement.getNumber<int>().getValue();
}

int C5NumberEngine::getInt(){
    auto requirement = this->requirements.at(this->requirementIndex);
    requirement.appendNumber<int>();
    return requirement.getNumber<int>().getValue();
}

double C5NumberEngine::getReal(double bmin, double bmax){
    //La verificación lanza una excepción en caso de que no se haya realizado.
    auto requirement = this->requirements.at(this->requirementIndex);
    requirement.appendNumber<double>(bmin, bmax);
    return requirement.getNumber<double>().getValue();
}
double C5NumberEngine::getReal(){
        //La verificación lanza una excepción en caso de que no se haya realizado.
    auto requirement = this->requirements.at(this->requirementIndex);
    requirement.appendNumber<double>();
    return requirement.getNumber<double>().getValue();
}
Stats C5NumberEngine::getStat() const{
    //La verificación lanza una excepción en caso de que no se haya realizado.
    auto requirement = this->requirements.at(this->requirementIndex);
    return requirement.getStats();
}
//A la mierda, devolvemos el vector de variants y a la chota.
const C5Requirement& C5NumberEngine::getNumberList() const{
    //La verificación lanza una excepción en caso de que no se haya realizado.
    return this->requirements.at(this->requirementIndex);
}
