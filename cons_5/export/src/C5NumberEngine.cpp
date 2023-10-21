#include "C5NumberEngine.h"
#include <cstdlib>
#include <ctime>
#include <utility>//ver después si realmente hace falta su inclusión

bool C5NumberEngine::userValidate(int userdId){
    std::ifstream validUsers(this->validUsersFile);
    std::string idRequest = std::to_string(userId);

    while std::getline(validUsers, id){
        if (id == idRequest){
            return true;
        }
    }
    return false;
}

int C5NumberEngine::getInt(int bmin, int bmax, int userId){
    if (bmax < bmin){//esto tiene que ver con la generación del numero en si
        throw std::__throw_invalid_argument("bmin debe ser menor o igual a bmax.");
    }
    std::srand(std::time(nullptr));
    int value = std::rand()%(bmax-bmin + 1);

    //esto que sigue tiene que ver con la gestión de requerimientos
    for(C5Requirement &requirement: this->requirements){
        if (requirement.getUserId() == userId){
            requirement.appendNumber(value, bmin, bmax);
            return value;
        }
    }
    this->requirements.push_back(C5Requirement(userId));//nuevo usuario
    this->requirements.back().appendNumber(value, bmin, bmax);
    return value;
}

int C5NumberEngine::getInt(int userId){
    /*Ver si lo siguiente después funciona cuando hay un vector vacio de requerimientos
    if (this->requirements.empty()){
        throw std::__throw_runtime_error("Sin rango previo para nueva solicitud.");
    }*/

    for(C5Requirement &requirement: this->requirements){
        if (requirement.getUserId() == userId){
            std::pair<int, int> boundary = requirement.getBoundary("entero");//obtiene el rango de la última petición entera, una tupla
            int bmmin = boundary.fist;
            int bmax = boundary.second;

            //hay que modificar las funciones para poder hacer esto:
            //this->getInt(boundary.first, boundary.second);

            std::srand(std::time(nullptr)); //en lugar de volver a repetir el código
            int value = std::rand()%(bmax-bmin + 1);
            requirement.appendNumber(value, bmin, bmax);
            return value;
        }
    }
    throw std::__throw_runtime_error("Sin rango previo para nueva solicitud.");
};

double C5NumberEngine::getReal(double bmin, double bmax, int userId){
    if (bmax < bmin){
        throw std::__throw_invalid_argument("bmin debe ser menor o igual a bmax.");
    }
    std::srand(std::time(nullptr));
    double value = bmin + static_cast<double>(std::rand())*(bmax-bmin)/RAND_MAX;

    for(C5Requirement &requirement: this->requirements){
        if (requirement.getUserId() == userId){
            requirement.appendNumber(value, bmin, bmax);
            return value;
        }
    }
    this->requirements.push_back(C5Requirement(userId));//nuevo usuario
    this->requirements.back().appendNumber(value, bmin, bmax);
    return value;
}
double C5NumberEngine::getReal(int userId){

}
C5NumberEngine::getNumberOld(int ordinal, int userId){

}
C5NumberEngine::getStat(int userId){

}
C5NumberEngine::getNumberList(int userid){

}