#include "CLI.h"
#include <limits> 
#include <cstdlib> 
#include <iostream>
#include <sstream>
#include <iomanip>


const map<string, string> CLI::methods = {
    {"validar", "userValidate"},
    {"entero", "getInt"},
    {"real", "getReal"},
    {"anterior", "getNumberOld"},
    {"estadistica", "getStat"},
    {"listar", "getNumberList"},
    {"h", "system.methodHelp"}
};

bool CLI::loop(XmlRpcClient& client, User& user)const{
    string line;
    string method;
    XmlRpcValue args;
    XmlRpcValue result;
    int id = user.getId();

    system("clear || cls");
    cout << this->menu();
    while(true) {
        cout << this->prompt();

        getline(cin, line);
        if (line == "q"){
            break;
        }
        else if(line == "m"){
            cout << this->menu();
        }
        else if(line == "l"){
            system("clear || cls");
        }
        else{
            args.clear();
            if (this->parseRequest(method, args, line, id)){
                result.clear();
                if (client.execute(method.c_str(), args, result)){
                    if (int(client.isFault()) == 0){
                        cout << this->parseResponse(method, result);
                    }
                    else{
                        cout << this->parseFaultResponse(method, result);
                    }
                }
                else{
                    cout << "\n- Error en la llamada al metodo " << method << "\n";
                }
            }
            else{
                cout << "\n- Sintaxis de comando incorrecta.\n";
            }
        }
    }
    cout << "\n- Hasta luego!\n" <<endl;

    return true;
}

string CLI::menu()const{
    stringstream menu;
    menu << "==================Comandos ======================\n";
    for (const auto &option: this->methods){
        menu <<"- "<<option.first << "\n";
    }
    menu << "\n";
    menu << "  Ingrese 'q' para salir.\n";
    menu << "  Ingrese 'm' para mostrar este menu.\n";
    menu << "  Ingrese 'l' para limipiar la pantalla.\n";
    menu << "=================================================";
    return menu.str();
}

bool CLI::parseRequest(string& method, XmlRpcValue& args, string& line, int id) const{
    stringstream input(line);
    string arg;

    input >> method;
    auto it = this->methods.find(method);
    if (it == this->methods.end()){
        return false;
    }
    method = it->second;

    unsigned int i = 0;
    if (method != "system.methodHelp"){
        args[0] = id;
        i++;
    }
    while(input >> arg){
        args[i] = arg;
        i++;
    }
    if (method == "system.methodHelp"){
        if (!args.valid()){
            args[0] = "system.methodHelp";
        }
        else if(args.size() == 1){
            it = this->methods.find(args[0]);
            if (it != this->methods.end()){
                args[0] = it->second;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    return this->validateArgs(method, args);
}
bool CLI::validateArgs(string& method, XmlRpcValue& args) const{
    if (method == this->methods.at("entero")){
        if(args.size() == 1){
            return true;
        }
        else{
            try{
                for(unsigned int i = 1; i < args.size(); i++){
                    args[i] = stoi(args[i]);
                }
                return true;
            }
            catch(const std::invalid_argument& e){
                return false;
            }
        }
    }
    else if (method == this->methods.at("real")){
        if(args.size() == 1){
            return true;
        }
        else{
            try{
                for(unsigned int i = 1; i < args.size(); i++){
                    args[i] = stof(args[i]);
                }
                return true;
            }
            catch(const invalid_argument& e){
                return false;
            }
        }
    }
    else if (method == this->methods.at("anterior")){
        if(args.size() == 1){
            return true;
        }
        else{
            try{
                for(unsigned int i = 1; i < args.size(); i++){
                    args[i] = stoi(args[i]);
                }
                return true;
            }
            catch(const invalid_argument& e){
                return false;
            }
        }
    }
    return true;
}
string CLI::prompt() const{
    stringstream prompt;
    prompt << '\n' <<">>> ";
    return prompt.str();
}

string CLI::parseResponse(string& method, XmlRpcValue& result) const{
    stringstream response;
    stringstream margin1, margin2;
    margin1 << setw(4) << right << setfill(' ') << ' ';
    margin2 << setw(8) << right << setfill(' ') << ' ';

    response << margin1.str() <<"respuesta:";

    if (method == this->methods.at("entero")||
        method == this->methods.at("real")  ||
        method == this->methods.at("validar")){

        response << margin1.str() << fixed << setprecision(2) << result;
    }
    else if (method == this->methods.at("anterior")
            ||method == this->methods.at("listar")){

        stringstream header;
        stringstream separator;
        int wid = 8;

        header  << '\n'
                << margin2.str()
                << setw(wid) << internal << setfill(' ') << "valor "<< '|'
                << setw(wid) << internal << setfill(' ') << "bmin " << '|'
                << setw(wid) << internal << setfill(' ') << "bmax " << '|'
                << setw(wid) << internal << setfill(' ') << "stamp "<< '|'
                << setw(wid) << internal << setfill(' ') << "tipo " << '\n';

        separator << margin2.str()
                  << setw(6*wid) << internal << setfill('-')
                  << '\n';

        response << '\n' << header.str() << separator.str();
        if (method == this->methods.at("anterior")){
            response << margin2.str()
                     << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[0] << '|'
                     << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[1] << '|'
                     << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[2] << '|'
                     << setw(wid) << internal << setfill(' ') << result[3] << '|'
                     << setw(wid) << internal << setfill(' ') << result[4];
        }
        else if(method == this->methods.at("listar")){
            for(unsigned int i = 0; i < result.size(); i++){
                response << margin2.str()
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][0] << '|'
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][1] << '|'
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][2] << '|'
                         << setw(wid) << internal << setfill(' ') << result[i][3] << '|'
                         << setw(wid) << internal << setfill(' ') << result[i][4];
            }
        }
    }
    else if (method == this->methods.at("estadistica")){
        int wid = 10;
        response << "\n\n"
                 << margin2.str()
                 << setw(wid) << internal << setfill(' ') << "cantidad "<< '|'
                 << setw(wid) << internal << setfill(' ') << "media "   << '|'
                 << setw(wid) << internal << setfill(' ') << "suma "    << '\n'
                 << margin2.str() << setw(4*wid) << internal << setfill('-') << '\n'
                 << margin2.str()
                 << setw(wid) << internal << setfill(' ') << result[0]  << '|'
                 << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[1]  << '|'
                 << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[2];
    }
    else if(method == this->methods.at("h")){
        stringstream lineas(result);
        string linea;
        response << '\n';
        while(getline(lineas, linea,'\n')){
            response << margin2.str()
                     << linea <<'\n';
        }
    }
    return response.str();
}
string CLI::parseFaultResponse(string& method, XmlRpcValue& result) const{
    stringstream response;
    stringstream margin1;
    stringstream margin2;
    margin1 << setw(4) << right << setfill(' ') << ' ';
    margin2 << setw(8) << right << setfill(' ') << ' ';
    response << margin1.str() << "ocurrio una excepcion !!\n"
             << margin2.str() <<"codigo  - " << result["faultCode"] << "\n"
             << margin2.str() <<"mensaje - " << result["faultString"];
    return response.str();
}