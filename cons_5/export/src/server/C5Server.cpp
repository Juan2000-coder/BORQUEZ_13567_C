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
    std::stringstream ayuda;
    ayuda << "Descripcion: valida al usuario segun su id.\n"
          << "Parametros: "
          << "{id (int)}.\n"
          << "Returns: "
          << "{validacion - (1 == vaildo) | (0 == no valido)}.";
    return ayuda.str();
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
    ayuda << "Descripcion: genera un numero entero aleatorio en un rango especificado.\n"
          << "Parametros: "
          << "{bmin(int) - limite inferior,"
          << " bmax(int) - limite superior}.\n"
          << "Returns: "
          << "{resultado(int)}.\n"
          << "Nota: si no se indica un rango se asume el de la ultima peticion.";
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
    ayuda << "Descripcion: genera un numero real aleatorio en un rango especificado.\n"
          << "Parametros: "
          << "{bmin(double) - limite inferior,"
          << " bmax(double) - limite superior}.\n"
          << "Returns:"
          << "{resultado(double)}.\n"
          << "Nota: si no se indica un rango se asume el de la ultima peticion.";
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
    ayuda << "Descripcion: devuelve informacion de un numero anterior.\n"
          << "Parametros: "
          << " {ordinal(int) - orden de la peticion}.\n"
          << "Returns:"
          << "{{valor(int|double),"
          << " bmin(int|double),"
          << " bmax(int|double),"
          << " timeStamp(string),"
          << " tipo(real|entero)}}.\n"
          << "Nota: timeStamp en segundos desde el inicio del proceso.";
    return ayuda.str();
}
void GetNumberOld::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    if (params.size() == 2){
        if(this->engine.userValidate(params[0])){
            try{
                const C5Number<int>& number = this->engine.getNumberOld<int>(params[1]);
                result[0] = number.getValue();
                result[1] = number.getBmin();
                result[2] = number.getBmax();
                result[3] = std::to_string(number.getTime());
                result[4] = number.getType();
                
            }
            catch(std::bad_variant_access){
                const C5Number<double>& number = this->engine.getNumberOld<double>(params[1]);
                result[0] = number.getValue();
                result[1] = number.getBmin();
                result[2] = number.getBmax();
                result[3] = std::to_string(number.getTime());
                result[4] = number.getType();
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
    std::stringstream ayuda;
    ayuda << "Descripcion: devuelve la estadistica basica de los numeros generados.\n"
          << "Returns: "
          << "{estadistica - {cantidad(int),"
          << " media(double),"
          << " suma(int|double)}}.";
    return ayuda.str();
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
    std::stringstream ayuda;
    ayuda << "Descripcion: devuelve la lista de los numeros generados.\n"
          << "Returns: "
          << "{lista - {{valor(int|double),"
          << " bmin(int|double),"
          << " bmax(int|double),"
          << " timeStamp(string),"
          << " tipo(entero|real)},"
          << "...},"
          << " timeStamp(string)}.\n"
          << "Nota: timeStamp en segundos desde el inicio del proceso.";
    return ayuda.str();
}
void GetNumberList::execute(XmlRpcValue& params, XmlRpcValue& result){
    if (params.size() == 1){
        if(this->engine.userValidate(params[0])){
            const C5Requirement & list = this->engine.getNumberList();
            for(int i = 0; i < list.getNumbersCount(); i++){
                try{
                    const C5Number<int> & number = list.getNumber<int>(i + 1);
                    result[i][0] = number.getValue();
                    result[i][1] = number.getBmin();
                    result[i][2] = number.getBmax();
                    result[i][3] = std::to_string(number.getTime());
                    result[i][4] = number.getType();
                }
                catch(std::bad_variant_access){
                    const C5Number<double> & number = list.getNumber<double>(i + 1);
                    result[i][0] = number.getValue();
                    result[i][1] = number.getBmin();
                    result[i][2] = number.getBmax();
                    result[i][3] = std::to_string(number.getTime());
                    result[i][4] = number.getType();
                }
            }
            auto stamp = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::seconds>(stamp-list.getInitialTime());
            result[result.size()] = std::to_string(duration.count());
        }
        else{
            result = false;
        }
    }
    else{
        throw ServerException(ServerException::exceptionCodes::INV_SYN);
    }
}