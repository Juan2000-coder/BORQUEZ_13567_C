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

C5RequirementException::C5RequirementException(int exceptionCode){
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
C5NumberEngineException::C5NumberEngineException(int exceptionCode){
    this->exceptionCode = exceptionCode;
    switch(exceptionCode){
        case 1:
            this->message = "No se pudo abrir el archivo de validación.";
            break;
        case 2:
            this->message = "Se requiere validacion de usuario antes del llamado.";
            break;
        default:
            this->message = "Excepcion no especificada.";
    }
}
ServerExceptions::ServerExceptions(int exceptionCode){
    this->exceptionCode = exceptionCode;
    switch(exceptionCode){
        case 1:
            this->message = "Sintáxis de orden incorrecta.";
            break;
        case 2:
            this->message = "Se requiere validacion de usuario antes del llamado.";
            break;
        default:
            this->message = "Excepcion no especificada.";
    }   
}