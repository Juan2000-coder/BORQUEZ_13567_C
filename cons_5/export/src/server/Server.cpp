#include "XmlRpc.h"
#include "C5Server.h"
#include <iostream>
#include <cstdlib>

using namespace XmlRpc;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Uso: Server Puerto verbosity\n";
    return -1;
  }

  int port = atoi(argv[1]);
  int verbosity = atoi(argv[2]);

  C5Server myServer;
  XmlRpc::setVerbosity(verbosity);

  myServer.bindAndListen(port);
  myServer.enableIntrospection(true);
  myServer.work(-1.0);
  std::cout << "Presione 'q' para salir."<< std::endl;
  
  myServer.shutdown();
  return 0;
}

