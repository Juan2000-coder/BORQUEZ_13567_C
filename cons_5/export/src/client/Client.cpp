#include "C5User.h"
#include "C5CLI.h"
#include "XmlRpc.h"
#include <iostream>

using namespace std;
using namespace XmlRpc;

int main(int argc, char* argv[]){
    if (argc != 4) {
        cerr << "Uso: Client IP PUERTO ID\n";
        return -1;
    }
    C5Client client(argv[1], atoi(argv[2]));
    C5User user(atoi(argv[3]));
    XmlRpcValue validation;
    if (client.execute("userValidate", user.getId(), validation)){
        if (int(validation) == 1){
            C5CLI cli;
            client.setXmlFile("Xmlfile.xml");
            if (cli.loop(client, user))
                return 0;
            else
                return -1;
        }
        cout << "Usuario no valido.\n";
        return 0;
    }
    else{
        cout << "Error al validar\n";
        return -1;
    }
}
