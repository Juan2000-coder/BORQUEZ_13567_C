#include "User.h"
#include "CLI.h"
#include "XmlRpc.h"
#include <iostream>

using namespace std;
using namespace XmlRpc;

int main(int argc, char* argv[]){
    if (argc != 4) {
        cerr << "Uso: Client IP PUERTO ID\n";
        return -1;
    }
    XmlRpcClient client(argv[1], int(argv[2]));
    User user(argv[3]);
    XmlRpcValue validation, id;
    if (client.execute("userValidate", id, validation)){
        if (validation){
            CLI cli;
            if (cli.loop(client, user))
                return 0;
            else
                return -1;
        }
        cout << "Usuario no valido.";
        return 0;
    }
    else{
        cout << "Error al validar";
        return -1;
    }
}
