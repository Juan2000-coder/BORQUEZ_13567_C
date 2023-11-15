/**
 * @file    Server.cpp
 * @brief   Main program of the XML-RPC Server.
 * 
 * @details
 * This file contains the main implementation of the XML-RPC Server.
 * 
 * @calling
 * Executable: ./server <port> <verbosity>
 * 
 * @description
 * Sets up the server and puts it to work.
 * 
 * @version  1.0
 * @date     2023-11-15
 * @author   Juan Manuel Borquez
 * @contact  borquez.juan00@gmail.com
 */

#include "XmlRpc.h"
#include "C5Server.h"
#include <iostream>
#include <cstdlib>

using namespace XmlRpc;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Uso: ./server <puerto> <verbosity>\n";
    return -1;
  }
  std::cout << "Presione 'CTRL + C' para salir."<< std::endl;

  int port = atoi(argv[1]);
  int verbosity = atoi(argv[2]);

  C5Server myServer;
  XmlRpc::setVerbosity(verbosity);
  myServer.bindAndListen(port);
  
  // Enable introspection for help in the server methods.
  myServer.enableIntrospection(true);
  myServer.work(-10);   // Listen to requirement for ever.
  return 0;
}