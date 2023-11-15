#ifndef _C5CLI_H
#define _C5CLI_H

#include "XmlRpc.h"
#include "C5User.h"
#include "C5Client.h"
#include <map>
#include <tuple>
#include <string>

using namespace XmlRpc;
using namespace std;

/**
 * @class C5CLI
 * @brief Class representing the Command Line Interface (CLI) to interact with a server using XmlRpc.
 */
class C5CLI {
public:
    /**
     * @brief Starts a loop of interaction with the provided client and user.
     * @param client Reference to a C5Client object representing the connection to the server.
     * @param user Reference to a C5User object representing user information.
     * @return true if the loop runs successfully, false otherwise.
     */
    bool loop(C5Client& client, C5User& user) const;

    /**
     * @brief Parses a provided request and extracts the method, arguments, and identifier.
     * @param method Reference to a string that will store the extracted method.
     * @param args Reference to an XmlRpcValue object that will store the extracted arguments.
     * @param line Reference to a string representing the request line.
     * @param id Identifier of the request.
     * @return true if the request is parsed successfully, false otherwise.
     */
    bool parseRequest(string& method, XmlRpcValue& args, string& line, int id) const;

    /**
     * @brief Validates the arguments of a specific method.
     * @param method String representing the method whose arguments are to be validated.
     * @param args Reference to an XmlRpcValue object containing the arguments to validate.
     * @return true if the arguments are valid, false otherwise.
     */
    bool validateArgs(string& method, XmlRpcValue& args) const;

    /**
     * @brief Returns a menu of available options.
     * @return String representing the menu of options.
     */
    string menu() const;

    /**
     * @brief Parses the response of a request and returns the representation in string format.
     * @param method String representing the method of the request.
     * @param result Reference to an XmlRpcValue object containing the result of the request.
     * @return String representing the parsed response.
     */
    string parseResponse(string& method, XmlRpcValue& result) const;

    /**
     * @brief Parses the response of an error request (fault) and returns the representation in string format.
     * @param method String representing the method of the error request.
     * @param result Reference to an XmlRpcValue object containing the result of the error request.
     * @return String representing the parsed error response.
     */
    string parseFaultResponse(string& method, XmlRpcValue& result) const;

    /**
     * @brief Generates a prompt for the Command Line Interface (CLI).
     * @return String representing the prompt.
     */
    string prompt() const;

private:
    static const map<string, string> methods;  ///< Map associating method names with descriptions.
};

#endif
