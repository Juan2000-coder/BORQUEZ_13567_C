#include "C5Exceptions.h"

std::ostream& operator<<(std::ostream& os, const C5Exceptions& myException){
    os << "Excepcion en " << myException.where() << " con codigo "
    << myException.getCode() << '\n' << "Mensaje: " << myException.what()
    << std::endl;
    return os;
}

C5NumberException::C5NumberException(exceptionCodes code){
    this->code = static_cast<unsigned int>(code);
    switch(code){
        case LIMIT:
            this->message = "Limite de numero invalido para el constructor";
            break;
        case TYPE:
            this->message = "Tipo de dato de limite invalido para el constructor";
            break;
        default:
            this->message = "No identificada.";
    }
}

C5RequirementException::C5RequirementException(exceptionCodes code){
    this->code = static_cast<unsigned int>(code);
    switch(code){
        case OUT_OF_RNG:
            this->message = "Ordinal fuera de rango";
            break;
        case NO_PREV_REQ:
            this->message = "Sin requerimientos previos";
            break;
        case NO_PREV_REQ_TYPE:
            this->message = "Sin requerimientos previos del tipo indicado";
            break;
        default:
            this->message = "No identificada";
    }
}
C5NumberEngineException::C5NumberEngineException(exceptionCodes code){
    this->code = static_cast<unsigned int>(code);
    switch(code){
        case AT_OPEN:
            this->message = "No se pudo abrir el archivo de validacion";
            break;
        default:
            this->message = "No identificada";
    }
}
ServerExceptions::ServerExceptions(exceptionCodes code){
    this->code = static_cast<unsigned int>(code);
    switch(code){
        case INV_SYN:
            this->message = "Sintaxis de orden incorrecta";
            break;
        default:
            this->message = "No identificada";
    }   
}