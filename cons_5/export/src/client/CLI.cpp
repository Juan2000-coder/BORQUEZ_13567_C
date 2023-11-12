#include "CLI.h"
#include <limits> 
#include <cstdlib> 
#include <iostream>
#include <sstream>


const map<string, string> CLI::methods = {
    {"validacion", "userValidate"},
    {"entero", "getInt"},
    {"real", "getReal"},
    {"anterior", "getNumberOld"},
    {"listar", "list"},
    {"estadistica", "getStat"},
    {"validar", "getNumberList"},
    {"h", "system.methodHelp"},
    {"q", "salir"}
};

bool CLI::loop(XmlRpcClient& client, User& user)const{
    string line;
    string method;
    XmlRpcValue args;
    XmlRpcValue result;
    bool service = true;
    string id = user.getId();
    
    while(service) {
        this->menu();

        cout << "Seleccione una opcion: ";
        getline(cin, line);

        args.clear();
        if (this->parse(method, args, line, id)){
            if (method == "salir"){
                service = false;
            }
            else{
                result.clear();
                if (client.execute(method.c_str(), args, result)){
                    cout << method <<": fault: " << client.isFault() << ", result = " << result << std::endl;
                }
                else{
                    cout << "Error en la llamada al metodo " << method << endl;
                }
                cout << "Presione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        }
        else{
            cout << "Sintaxis de comando incorrecta.";
        }
        system("clear || cls"); // Limpiar la pantalla
    }

    cout << "¡Hasta luego!" <<endl;

    return true;
}
void CLI::menu()const{
    cout << "======= Comandos =======\n";
    for (const auto &option: this->methods){
        cout << option.first << "\n";
    }
    cout << "=====================\n";
}

bool CLI::parse(string& method, XmlRpcValue& args, string& line, string id)const{
    stringstream input(line);
    string arg;

    input >> method;
    auto it = this->methods.find(method);
    if (it == this->methods.end()){
        cout << "Opcion no valida. Por favor, seleccione una opcion valida.\n";
        return false;
    }

    unsigned int i = 0;
    if ((method != "system.methodHelp")&&(method != "salir")){
        args[0] = id;
        i++;
    }
    while(input >> arg){
        args[i] = arg;
        i++;
    }

    if ((method == "salir")&&(args.size())){
        return false;
    }

    cout << "Seleccionaste " << method << endl;
    return true;
}