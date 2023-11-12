#include "C5Number.h"
#include "C5Exceptions.h"
#include <ctime>

template<class Type>
C5Number<Type>::C5Number(Type bmin, Type bmax, long time){
    std::srand(std::time(nullptr));

    if (std::is_same<Type, double>::value){
        this->type = "real";
        if (bmin <= bmax){
            this->value = bmin + double(std::rand())*(bmax - bmin)/RAND_MAX;
        }
        else{
            throw C5NumberException(C5NumberException::exceptionCodes::LIMIT);
        }
    }
    else if(std::is_same<Type, int>::value){
        this->type = "entero";
        if (bmin <= bmax){
            this->value = bmin + std::rand()%static_cast<int>(bmax-bmin + 1);
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