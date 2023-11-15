/**
 * @file  C5Requirement.cpp
 * @brief Implementation of the C5Requirement class.
 * 
 * @details This file contains the implementation of the C5Requirement class methods.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */

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
    // Current Time Stamp: The number of seconds since the creation of the requirement.
    auto checkpoint = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::seconds>(checkpoint-this->getInitialTime());
    long timestamp = duracion.count();
    return timestamp;
}

C5Stats C5Requirement::getStats()const{
    double sum = 0;
    double mean = 0;

    if(!this->numbers.empty()){
        for(auto number: this->numbers){
            if(std::holds_alternative<C5Number<int>>(number)){
                sum += std::get<C5Number<int>>(number).getValue();
            }
            else{
                sum += std::get<C5Number<double>>(number).getValue();
            }
        }
        mean = sum/this->numbers.size();
    }
    return C5Stats(sum, mean, this->numbers.size());
}