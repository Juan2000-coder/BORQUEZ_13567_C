#include "CLI.h"
#include <limits> 
#include <cstdlib> 
#include <iostream>
#include <sstream>


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
    this->menu();
    while(true) {
        this->prompt();

        getline(cin, line);
        if (line == "q"){
            break;
        }
        else if(line == "m"){
            this->menu();
        }
        else if(line == "l"){
            system("clear || cls");
        }
        else{
            args.clear();
            if (this->parse(method, args, line, id)){
                result.clear();
                if (client.execute(method.c_str(), args, result)){
                    if (int(client.isFault()) == 0){
                        cout << "\n- Respuesta del servidor: "<< result <<"\n";
                    }
                    else{
                        cout << "\n- Se recibio una respuesta con error: "<< result << "\n";
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

void CLI::menu()const{
    cout << "==================Comandos ======================\n";
    for (const auto &option: this->methods){
        cout <<"- "<<option.first << "\n";
    }
    cout << "\n";
    cout << "  Ingrese 'q' para salir.\n";
    cout << "  Ingrese 'm' para mostrar este menu.\n";
    cout << "  Ingrese 'l' para limipiar la pantalla.\n";
    cout << "=================================================\n\n";
}

bool CLI::parse(string& method, XmlRpcValue& args, string& line, int id) const{
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
void CLI::prompt() const{
    cout << '\n' <<">>> ";
}