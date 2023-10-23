#include "XmlRpc.h"
#include "C5Server.h"
#include "C5Exceptions.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>

using namespace XmlRpc;

void UserValidate::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: falta ver excepciones por numero de parámetros y por tipo de dato de entrada*/
    try{
        if (params.size() == 1){
            if(this->engine.userValidate(params[0])){
                result = "Usuario Válido.";
            }
            else{
                result = "Usuario no Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
}


void GetInt::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    try{
        if (params.size() == 1){
            if(this->engine.userValidate(params[0])){
                result = this->engine.getInt(params[0]);
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else if(params.size() == 3){
            if(this->engine.userValidate(params[0])){
                result = this->engine.getInt(params[0], params[1], params[2]);
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }

}

void GetReal::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    try{
        if (params.size() == 1){
            if(this->engine.userValidate(params[0])){
                result = this->engine.getReal(params[0]);
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else if(params.size() == 3){
            if(this->engine.userValidate(params[0])){
                result = this->engine.getReal(params[0], params[1], params[2]);
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
}

void GetNumberOld::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    try{
        if (params.size() == 2){
            if(this->engine.userValidate(params[0])){
                try{
                    auto number = this->engine.getNumberOld<int>(params[0], params[1]);
                    result[0] = number.getValue();
                    result[1] = number.getBmin();
                    result[2] = number.getBmax();
                    result[3] = std::to_string(number.getTime());
                    
                }
                catch(std::bad_variant_access()){
                    auto number = this->engine.getNumberOld<double>(params[0], params[1]);
                    result[0] = number.getValue();
                    result[1] = number.getBmin();
                    result[2] = number.getBmax();
                    result[3] = std::to_string(number.getTime());
                }
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
}

void GetStat::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/
    try{
        if (params.size() == 1){
            if(this->engine.userValidate(params[0])){
                auto stat = this->engine.getStat(params[0]);
                result[0] = stat.getCount();
                result[1] = stat.getMean();
                result[2] = stat.getSum();
            }
            else{
                result = "Usuario No Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
}

void GetNumberList::execute(XmlRpcValue& params, XmlRpcValue& result){
    try{
        if (params.size() == 1){
            if(this->engine.userValidate(params[0])){
                auto list = this->engine.getNumberList(params[0]);
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
                result = "Usuario No Válido.";
            }
        }
        else{
            throw ServerExceptions(1);
        }
    }
    catch(ServerExceptions &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Server con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Number con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5RequirementException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5Requirement con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(C5NumberEngineException &e){
        std::stringstream ss;
        ss << "Excepcion de Modulo C5NumberEngine con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
    catch(std::exception &e){
        std::stringstream ss;
        ss << "Excepcion no especificada con mensaje: "<< e.what() << std::endl;
        std::cerr << ss.str();
        result = ss.str();
    }
}