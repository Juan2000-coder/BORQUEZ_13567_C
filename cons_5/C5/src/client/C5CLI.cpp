/**
 * @file    C5CLI.cpp
 * @brief   Implementation of the C5CLI class.
 * 
 * @details This file contains the implementation of the C5CLI class, which
 * is responsible for handling the command-line interface of the XML-RPC client.
 * It includes methods for processing user input, executing XML-RPC requests,
 * and displaying the results.
 * 
 * @version 1.0
 * @date    2023-11-15
 * @author  Juan Manuel Borquez
 * @contact borquez.juan00@gmail.com
 */

#include "C5CLI.h"
#include <limits> 
#include <cstdlib> 
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief Dictionary mapping command names to corresponding XML-RPC methods.
 */
const map<string, string> C5CLI::methods = {
    {"validar", "userValidate"},
    {"entero", "getInt"},
    {"real", "getReal"},
    {"anterior", "getNumberOld"},
    {"estadistica", "getStat"},
    {"listar", "getNumberList"},
    {"help", "system.methodHelp"}
};

bool C5CLI::loop(C5Client& client, C5User& user)const{
    string line;
    string method;
    XmlRpcValue args;
    XmlRpcValue result;
    int id = user.getId();

    system("clear || cls");
    cout << this->menu();

    while(true) {
        // ... (input handling)
        cout << this->prompt();
        getline(cin, line);

        if (line == "q"){  // quit
            break;
        }
        else if(line == "menu"){
            cout << this->menu();
        }
        else if(line == "clear"){
            system("clear || cls");
            cout << this->menu();
        }
        else{
            // ... (parsing and executing XML-RPC request)

            args.clear();

            if (this->parseRequest(method, args, line, id)){
                result.clear();

                if (client.execute(method.c_str(), args, result)){
                    if (int(client.isFault()) == 0){
                        cout << this->parseResponse(method, result);
                    }
                    else{//Fault Response
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
    cout << "\n- Hasta luego!\n" << endl;

    return true;
}

string C5CLI::menu()const{
    stringstream menu;
    menu << "================================ Comandos =============================\n";
    for (const auto &option: this->methods){
        menu <<"- "<<option.first << "\n";
    }
    menu << "\n";
    menu << "  Ingrese 'q' para salir.\n";
    menu << "  Ingrese 'menu' para mostrar este menu.\n";
    menu << "  Ingrese 'clear' para limipiar la pantalla.\n";
    menu << "\n  Sintaxis de orden: 'comando' 'parametros separados por espacios.'\n";
    menu << "=======================================================================";
    return menu.str();
}

bool C5CLI::parseRequest(string& method, XmlRpcValue& args, string& line, int id) const {
    stringstream input(line);
    string arg;

    // Extract the method name from the input and map it to the corresponding XML-RPC method.
    input >> method;
    auto it = this->methods.find(method);
    if (it == this->methods.end()) {// Invalid method
        return false;
    }

    method = it->second;
    unsigned int i = 0;

    // For methods other than 'system.methodHelp', set the first argument to the user ID.
    if (method != "system.methodHelp") {
        args[0] = id;
        i++;
    }

    // Parse the remaining arguments from the input.
    while (input >> arg) {
        args[i] = arg;
        i++;
    }

    // Special handling for 'system.methodHelp' method.
    if (method == "system.methodHelp") {
        // If no arguments are provided, set "system.methodHelp" as the first argument.
        if (!args.valid()) {
            args[0] = "system.methodHelp";
        }
        // If one argument is provided, map it to the corresponding XML-RPC method.
        else if (args.size() == 1) {
            it = this->methods.find(args[0]);
            if (it != this->methods.end()) {
                args[0] = it->second;
            }
            else {
                return false;
            }
        }
        else { // Invalid Syntax
            return false;
        }
    }

    // Validate the arguments.
    return this->validateArgs(method, args);
}

bool C5CLI::validateArgs(string& method, XmlRpcValue& args) const {
    if (method == this->methods.at("entero")) {
        if (args.size() == 1) { // Just user id provided.
            return true;
        } else {
            try {
                // Convert each string argument to integer.
                for (unsigned int i = 1; i < args.size(); i++) {
                    args[i] = stoi(args[i]);
                }
                return true;
            } catch (const std::invalid_argument& e) {// Coudn´t cast to int.
                return false;
            }
        }
    } else if (method == this->methods.at("real")) {
        if (args.size() == 1) {// Just user id provided.
            return true;
        } else {
            try {
                // Convert each argument to float.
                for (unsigned int i = 1; i < args.size(); i++) {
                    args[i] = stof(args[i]);
                }
                return true;
            } catch (const std::invalid_argument& e) {// Coudn´t cast to float.
                return false;
            }
        }
    } else if (method == this->methods.at("anterior")) {
        if (args.size() == 1) {// Just user id provided.
            return true;
        } else {
            try {
                // Convert each argument to integer.
                for (unsigned int i = 1; i < args.size(); i++) {
                    args[i] = stoi(args[i]);
                }
                return true;
            } catch (const std::invalid_argument& e) {// Coudn´t cast to int.
                return false;
            }
        }
    }

    // Default case: No specific validation required for other methods.
    return true;
}

string C5CLI::prompt() const{
    stringstream prompt;
    prompt << '\n' <<">>> ";
    return prompt.str();
}

string C5CLI::parseResponse(string& method, XmlRpcValue& result) const{
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
        int wid = 9;

        header  << '\n'
                << margin2.str()
                << setw(wid) << internal << setfill(' ') << "valor "<< '|'
                << setw(wid) << internal << setfill(' ') << "bmin " << '|'
                << setw(wid) << internal << setfill(' ') << "bmax " << '|'
                << setw(wid) << internal << setfill(' ') << "stamp(s) "<< '|'
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
            for(unsigned int i = 0; i < result.size() - 1; i++){
                response << margin2.str()
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][0] << '|'
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][1] << '|'
                         << setw(wid) << internal << setfill(' ') << fixed << setprecision(2) << result[i][2] << '|'
                         << setw(wid) << internal << setfill(' ') << result[i][3] << '|'
                         << setw(wid) << internal << setfill(' ') << result[i][4] << '\n';
            }
            response << "\n" << margin2.str() <<"Tiempo transcurrido(s): " << result[result.size() - 1];
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
    else if(method == this->methods.at("help")){
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
string C5CLI::parseFaultResponse(string& method, XmlRpcValue& result) const{
    stringstream response;
    stringstream margin1;
    stringstream margin2;
    margin1 << setw(4) << right << setfill(' ') << ' ';
    margin2 << setw(8) << right << setfill(' ') << ' ';
    response << margin1.str() << "ocurrio una excepcion !!\n"
             << margin2.str() << "codigo  - " << result["faultCode"] << "\n"
             << margin2.str() << "mensaje - " << result["faultString"];
    return response.str();
}