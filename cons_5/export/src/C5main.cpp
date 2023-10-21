#include "C5NumberEngine.h"
#include <iostream>

int main(int argc, const char* argv[]) {
    if (argc != 2){
        std::cerr << "El uso es: NumberEngine Puerto" << std::endl;
        return -1;
    }

    XmlRpc::setVerbosity(1);

    C5NumberEngine engine;

    int port = int(argv[1]);

    // Create the server socket on the specified port
    engine.bindAndListen(port);

    // Enable introspection
    engine.enableIntrospection(true);
    
    // Wait for requests indefinitely
    engine.work(-1.0);

    return EXIT_SUCCESS;
}