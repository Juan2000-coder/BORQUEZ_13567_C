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
  std::cout << "Presione 'CTRL + C' para salir."<< std::endl;

  int port = atoi(argv[1]);
  int verbosity = atoi(argv[2]);

  C5Server myServer;
  XmlRpc::setVerbosity(verbosity);
  myServer.bindAndListen(port);
  myServer.enableIntrospection(true);
  myServer.work(-10);
  return 0;
}