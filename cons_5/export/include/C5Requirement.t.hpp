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
void C5Requirement::appendNumber(){
    const C5Number<Type>& number = this->getRecent<Type>();
    this->appendNumber(number.getBmin(), number.getBmax(), this->getCurrentStamp());
}

template<typename Type>
const C5Number<Type> &C5Requirement:: getNumber(int ordinal) const{
    /*Se produce una excepción media complicada de manejar. Mejor lanzamos una.*/

    if ((ordinal > 0)&&(this->numbers.size() >= ordinal)){
        return std::get<C5Number<Type>>(this->numbers.at(ordinal-1));
    }
    throw C5ReqirementException(1);

}

template<typename Type>
const C5Number<Type> &C5Requirement::getNumber()const{
    if(!this->numbers.empty()){
        /*Eto todavía puede lanzar una exceptión de bad access*/
        return std::get<C5Number<Type>>(this->numbers.back());
    }
    throw C5ReqirementException(2);
}

template<typename Type>
const C5Number<Type> &C5Requirement::getRecent()const{
    for(auto rit = this->numbers.rbegin(); rit != numbers.rend(); rit++){
        if(std::holds_alternative<C5Number<Type>>(*rit)){
            return std::get<C5Number<Type>>(*rit);
        }
    }
    throw C5ReqirementException(3);
}

Stats C5Requirement::getStats()const{
    //No sabemos si puede tirar excepciones a priori esta llamada
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
    return Stats(sum, mean, this->numbers.size());
}