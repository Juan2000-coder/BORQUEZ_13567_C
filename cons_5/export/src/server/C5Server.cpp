#include "XmlRpc.h"
#include "C5Server.h"
#include "C5Exceptions.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace XmlRpc;
C5ServerConnection* C5Server::createConnection(int socket){
    return new C5ServerConnection(socket, this, true);
}

std::string UserValidate::help(){
    return "Valida al usuario segun su id (valido = 1) (no valido = 0)";
}
void UserValidate::execute(XmlRpcValue& params, XmlRpcValue& result){
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            result = true;
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}

std::string GetInt::help(){
    std::stringstream ayuda;
    ayuda <<  "Genera un numero entero aleatorio en un rango especificado (bmin, bmax).\n"
           << "Si no se indica un rango se toma el correspondiente a la ultima solicitud.";
    return ayuda.str();
}
void GetInt::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            result = this->engine.getInt();
        }
        else{
            result = false;
        }
    }
    else if(params.size() == 3){
        if(this->engine.userValidate(params[0])){
            result  = this->engine.getInt(params[1], params[2]);
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}

std::string GetReal::help(){
    std::stringstream ayuda;
    ayuda <<  "Genera un numero real aleatorio en un rango especificado (bmin, bmax).\n"
           << "Si no se indica un rango se toma el correspondiente a la ultima solicitud.";
    return ayuda.str();
}
void GetReal::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            result = this->engine.getReal();
        }
        else{
            result = false;
        }
    }
    else if(params.size() == 3){
        if(this->engine.userValidate(params[0])){
            result = this->engine.getReal(params[1], params[2]);
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}

std::string GetNumberOld::help(){
    std::stringstream ayuda;
    ayuda << "Devuelve el numero generado en el orden indicado por un ordinal.";
    return ayuda.str();
}
void GetNumberOld::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    if (params.size() == 2){
        if(this->engine.userValidate(params[0])){
            try{
                auto number = this->engine.getNumberOld<int>(params[1]);
                result[0] = number.getValue();
                result[1] = number.getBmin();
                result[2] = number.getBmax();
                result[3] = std::to_string(number.getTime());
                
            }
            catch(std::bad_variant_access()){
                auto number = this->engine.getNumberOld<double>(params[1]);
                result[0] = number.getValue();
                result[1] = number.getBmin();
                result[2] = number.getBmax();
                result[3] = std::to_string(number.getTime());
            }
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}

std::string GetStat::help(){
    return "Devuelve la estadistica basica de los numeros generados.";
}
void GetStat::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            auto stat = this->engine.getStat();
            result[0] = stat.getCount();
            result[1] = stat.getMean();
            result[2] = stat.getSum();
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}

std::string GetNumberList::help(){
    return "Devuelve el listado de numeros generados.";
}
void GetNumberList::execute(XmlRpcValue& params, XmlRpcValue& result){
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            auto list = this->engine.getNumberList();
            XmlRpcValue result1;
            XmlRpcValue result2;
            for(int i = 0; i < list.getNumbersCount(); i++){
                try{
                    auto number = list.getNumber<int>(i);
                    result1[i][0] = number.getValue();
                    result1[i][1] = number.getBmin();
                    result1[i][2] = number.getBmax();
                    result1[i][3] = std::to_string(number.getTime());
                    result1[i][4] = number.getType();
                }
                catch(std::bad_variant_access &e){
                    auto number = list.getNumber<int>(i);
                    result1[i][0] = number.getValue();
                    result1[i][1] = number.getBmin();
                    result1[i][2] = number.getBmax();
                    result1[i][3] = std::to_string(number.getTime());
                    result1[i][4] = number.getType();
                }
            }
            auto stamp = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(list.getInitialTime()-stamp);
            result2 = std::to_string(duration.count());
            result[0] = result1;
            result[1] = result2;
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}