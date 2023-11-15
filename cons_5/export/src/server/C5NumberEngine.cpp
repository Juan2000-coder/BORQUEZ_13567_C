#include "C5NumberEngine.h"
#include <cstdlib>
#include <ctime>
#include <utility>
#include <fstream>

C5NumberEngine::C5NumberEngine(){
    // Path relative to the buid folder.
    this->validUsersFile = "../files/users.txt";
}

bool C5NumberEngine::userValidate(int userId){
    int index = 0;
    for(C5Requirement &requirement: this->requirements){
        // Checks if the user is already in the list of requirements.
        if (requirement.getUserId() == userId){
            this->requirementIndex = index;
            return true; // User already in the list of requirements.
        }
        index++;
    }

    std::ifstream validUsers(this->validUsersFile);
    if (!validUsers.is_open()){
        throw C5NumberEngineException(C5NumberEngineException::exceptionCodes::AT_OPEN);
    }
    std::string idRequest = std::to_string(userId);
    std::string id;

    while (std::getline(validUsers, id)){// Checks if the user is in the file.
        if (id == idRequest){// Valid user.
            this->requirements.push_back(C5Requirement(userId)); // Creates a new Requirement.
            this->requirementIndex = this->requirements.size() - 1;
            return true;
        }
    }
    return false; // Not valid user.
}


int C5NumberEngine::getInt(int bmin, int bmax){
    auto &requirement = this->requirements.at(this->requirementIndex);

    // Creates a new number and then returns it's value.
    requirement.appendNumber<int>(bmin, bmax);
    return requirement.getNumber<int>().getValue();
}

int C5NumberEngine::getInt(){
    auto &requirement = this->requirements.at(this->requirementIndex);

    // Creates a new number and then returns it's value.
    requirement.appendNumber<int>();
    return requirement.getNumber<int>().getValue();
}

double C5NumberEngine::getReal(double bmin, double bmax){
    auto &requirement = this->requirements.at(this->requirementIndex);

    // Creates a new number and then returns it's value.
    requirement.appendNumber<double>(bmin, bmax);
    return requirement.getNumber<double>().getValue();
}
double C5NumberEngine::getReal(){
    auto &requirement = this->requirements.at(this->requirementIndex);

    // Creates a new number and then returns it's value.
    requirement.appendNumber<double>();
    return requirement.getNumber<double>().getValue();
}
Stats C5NumberEngine::getStat() const{
    auto requirement = this->requirements.at(this->requirementIndex);
    return requirement.getStats();
}
const C5Requirement& C5NumberEngine::getNumberList() const{
    return this->requirements.at(this->requirementIndex);
}
