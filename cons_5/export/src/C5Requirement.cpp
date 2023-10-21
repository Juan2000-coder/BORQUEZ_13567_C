#include "C5Requirement.h"
#include "C5Number.h"
#include <ctime>

//constructors
C5Requirement::C5Requirement(){
    this->initialTime = static_cast<long>(std::time(nullptr));
}

C5Requirement::C5Requirement(int userId): C5Requirement(){
    this->userId = userId;
}

//setters
void C5Requirement::setUserId(int id){
    this->userId = id;
}

//getters
int C5Requirement::getUserId() const{
    return this->userId;
}

long C5Requirement::getInitialTime() const{
    return this->initialTime;
}