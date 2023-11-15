#include "C5Requirement.h"
#include "C5Number.h"
#include "C5Exceptions.h"

template<typename Type>
void C5Requirement::appendNumber(Type bmin, Type bmax){
    C5Number<Type> number(bmin, bmax, this->getCurrentStamp());
    number.setOrdinal(this->numbers.size() + 1);
    this->numbers.push_back(number);
}

template<typename Type>
const C5Number<Type> &C5Requirement::getRecent()const{

    // Iterates over the vector of numbers
    for(auto rit = this->numbers.rbegin(); rit != numbers.rend(); rit++){
        if(std::holds_alternative<C5Number<Type>>(*rit)){

            // Stops and returns the first ocurrence of the Type specified
            return std::get<C5Number<Type>>(*rit); 
        }
    }
    throw C5RequirementException(C5RequirementException::exceptionCodes::NO_PREV_REQ_TYPE);
}

template<typename Type>
void C5Requirement::appendNumber(){
    const C5Number<Type>& number = this->getRecent<Type>();
    this->appendNumber(number.getBmin(), number.getBmax());
}

template<typename Type>
const C5Number<Type> &C5Requirement:: getNumber(int ordinal) const{
    if ((ordinal > 0)&&(this->numbers.size() >= ordinal)){ // Ordinal is in the range.
        return std::get<C5Number<Type>>(this->numbers.at(ordinal-1));
    }
    throw C5RequirementException(C5RequirementException::exceptionCodes::OUT_OF_RNG);

}

template<typename Type>
const C5Number<Type> &C5Requirement::getNumber()const{
    if(!this->numbers.empty()){
        return std::get<C5Number<Type>>(this->numbers.back());
    }
    throw C5RequirementException(C5RequirementException::exceptionCodes::NO_PREV_REQ);
}