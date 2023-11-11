// HelloClient.cpp : A simple xmlrpc client. Usage: HelloClient serverHost serverPort
// Link against xmlrpc lib and whatever socket libs your system needs (ws2_32.lib 
// on windows)

#include "XmlRpc.h"
#include <iostream>
using namespace XmlRpc;

int main(int argc, char* argv[])
{
  if (argc != 3) {
    std::cerr << "Usage: HelloClient serverHost serverPort\n";
    return -1;
  }
  int port = atoi(argv[2]);
  //XmlRpc::setVerbosity(5);

  // Use introspection API to look up the supported methods
  XmlRpcClient c(argv[1], port);
  XmlRpcValue noArgs, result;
  if (c.execute("system.listMethods", noArgs, result))
    std::cout << "\nMethods:\n " << result << "\n\n";
  else
    std::cout << "Error calling 'listMethods'\n\n";

  // Use introspection API to get the help string for the Hello method
  XmlRpcValue oneArg;
  oneArg[0] = "Hello";
  if (c.execute("system.methodHelp", oneArg, result))
    std::cout << "Help for 'Hello' method: " << result << "\n\n";
  else
    std::cout << "Error calling 'methodHelp'\n\n";

  // Call the Hello method
  oneArg[0] = "yo";
  if (c.execute("userValidate", oneArg, result))
    std::cout << result << "\n\n";
  else
    std::cout << "Error calling 'userValidate'\n\n";


  // Test the "no such method" fault
  if (c.execute("NoSuchMethod", noArgs, result))
    std::cout << "NoSuchMethod call: fault: " << c.isFault() << ", result = " << result << std::endl;
  else
    std::cout << "Error calling 'NoSuchMethod'\n";

  // Test the multicall method. It accepts one arg, an array of structs
  
  /*
  XmlRpcValue multicall;
  multicall[0][0]["methodName"] = "Sum";
  multicall[0][0]["params"][0] = 5.0;
  multicall[0][0]["params"][1] = 9.0;

  multicall[0][1]["methodName"] = "NoSuchMethod";
  multicall[0][1]["params"][0] = "";

  multicall[0][2]["methodName"] = "Sum";
  // Missing params

  multicall[0][3]["methodName"] = "Sum";
  multicall[0][3]["params"][0] = 10.5;
  multicall[0][3]["params"][1] = 12.5;

  if (c.execute("system.multicall", multicall, result))
    std::cout << "\nmulticall  result = " << result << std::endl;
  else
    std::cout << "\nError calling 'system.multicall'\n";
  */
  return 0;
}
