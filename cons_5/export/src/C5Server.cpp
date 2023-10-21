#include "XmlRpc.h"
#include "C5Server.h"

#include <fstream>
#include <vector>
#include <string>

using namespace XmlRpc;

void UserValidate::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: falta ver excepciones por numero de parámetros y por tipo de dato de entrada*/
}


void GetInt::execute(XmlRpcValue& params, XmlRpcValue& result){
    /*FALTA: Falta verificación del número de parámetros y verificación de tipos*/

}

void GetReal::execute(XmlRpcValue& params, XmlRpcValue& result){

}

void GetNumberOld::execute(XmlRpcValue& params, XmlRpcValue& result){

}

void GetStat::execute(XmlRpcValue& params, XmlRpcValue& result){

}

void GetNumberList::execute(XmlRpcValue& params, XmlRpcValue& result){

}

C5Server::C5Server(){
    XmlRpcServer();
    this->userValidate(this);
}