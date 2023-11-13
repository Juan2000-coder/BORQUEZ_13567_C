#include "C5Number.h"
#include "C5Exceptions.h"
#include <random>

template<class Type>
C5Number<Type>::C5Number(Type bmin, Type bmax, long time){
    std::random_device rd;
    std::mt19937 generator(rd());

    if (std::is_same<Type, double>::value){
        this->type = "real";
        if (bmin <= bmax){
            std::uniform_real_distribution<double> doubleDistribution(bmin, bmax);
            this->value = doubleDistribution(generator);

        }
        else{
            throw C5NumberException(C5NumberException::exceptionCodes::LIMIT);
        }
    }
    else if(std::is_same<Type, int>::value){
        this->type = "entero";
        if (bmin <= bmax){
            std::uniform_int_distribution<int> intDistribution(bmin, bmax);
            this->value = intDistribution(generator);

        }
        else{
            throw C5NumberException(C5NumberException::exceptionCodes::LIMIT);
        }
    }
    else{
        throw C5NumberException(C5NumberException::exceptionCodes::TYPE);
    }
    this->time = time;
    this->bmin = bmin;
    this->bmax = bmax;
}

//setters
template<class Type>
void C5Number<Type>::setOrdinal(int ordinal){
    this->ordinal = ordinal;
}

template<class Type>
int C5Number<Type>::getOrdinal() const{
    return this->ordinal;
}

template<class Type>
std::string C5Number<Type>::getType() const{
    return this->type;
}

template<class Type>
Type C5Number<Type>::getValue() const{
    return this->value;
}

template<class Type>
Type C5Number<Type>::getBmin() const{
    return this->bmin;
}

template<class Type>
Type C5Number<Type>::getBmax() const{
    return this->bmax;
}

template<class Type>
long C5Number<Type>::getTime() const{
    return this->time;
}