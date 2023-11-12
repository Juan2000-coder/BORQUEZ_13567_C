#include "XmlRpc.h"
#include "C5Server.h"
#include <iostream>
#include <cstdlib>

using namespace XmlRpc;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: Server serverPort\n";
    return -1;
  }

  int port = atoi(argv[1]);

  C5Server myServer;
  XmlRpc::setVerbosity(3);

  myServer.bindAndListen(port);
  myServer.enableIntrospection(true);
  myServer.work(-1.0);
  //myServer.shutdown(); Método para terminar con el servidor
  return 0;
}

