#include "C5Client.h"
#include <iostream>

bool C5Client::parseResponse(XmlRpcValue& result){
    // Parse response xml into result
    int offset = 0;
    if ( ! XmlRpcUtil::findTag(METHODRESPONSE_TAG,_response,&offset)) {
        XmlRpcUtil::error("Error in XmlRpcClient::parseResponse: Invalid response - no methodResponse. Response:\n%s", _response.c_str());
        return false;
    }

    // Expect either <params><param>... or <fault>...
    if ((XmlRpcUtil::nextTagIs(PARAMS_TAG,_response,&offset) &&
         XmlRpcUtil::nextTagIs(PARAM_TAG,_response,&offset)) ||
         XmlRpcUtil::nextTagIs(FAULT_TAG,_response,&offset) && (_isFault = true)){
        if ( ! result.fromXml(_response, &offset)) {
            XmlRpcUtil::error("Error in XmlRpcClient::parseResponse: Invalid response value. Response:\n%s", _response.c_str());
            _response = "";
            return false;
        }
    }
    else {
        XmlRpcUtil::error("Error in XmlRpcClient::parseResponse: Invalid response - no param or fault tag. Response:\n%s", _response.c_str());
        _response = "";
        return false;
    }
    this->dumToFile(_response);
    _response = "";
    return result.valid();
}
void C5Client::setXmlFile(std::string file){
    this->XmlFile = "../files/" + file;
}
bool C5Client::dumToFile(std::string response){
    std::ofstream file(this->XmlFile, std::ios::app);
    if (file.is_open()) {
        file << response; 
        file.close();
        return true;
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return false;
    }
}