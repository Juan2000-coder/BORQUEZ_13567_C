#include "C5Exceptions.h"

C5NumberException::C5NumberException(int exceptionCode){
    this->exceptionCode = exceptionCode;
    switch(exceptionCode){
        case 1:
            this->message = "Limite de numero invalido para el constructor.";
            break;
        case 2:
            this->message = "Tipo de dato de limite invalido para el constructor.";
            break;
        default:
            this->message = "Excepcion no especificada.";
    }
}

C5ReqirementException::C5ReqirementException(int exceptionCode){
    this->exceptionCode = exceptionCode;
    switch(exceptionCode){
        case 1:
            this->message = "Ordinal fuera de rango.";
            break;
        case 2:
            this->message = "Sin requerimientos previos.";
            break;
        case 3:
            this->message = "Sin requerimientos previos del tipo indicado.";
            break;
        default:
            this->message = "Excepcion no especificada.";
    }
}