#include "C5Requirement.h"
#include "C5Number.h"
#include <chrono>

//constructors
C5Requirement::C5Requirement(){
    this->initialTime = std::chrono::high_resolution_clock::now();
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

std::chrono::_V2::system_clock::time_point C5Requirement::getInitialTime() const{
    return this->initialTime;
}

int C5Requirement::getNumbersCount() const{
    return this->numbers.size();
}

long C5Requirement::getCurrentStamp() const{
    auto checkpoint = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::seconds>(checkpoint-this->getInitialTime());
    long timestamp = duracion.count();
    return timestamp;
}