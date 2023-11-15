#include "C5User.h"
#include "C5CLI.h"
#include "XmlRpc.h"
#include <iostream>

using namespace std;
using namespace XmlRpc;

/**
 * @brief The main function for client part.
 *
 * Validates the main args, initializes a client, sets the XML file,
 * validates the user, and starts the command-line interface loop.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return Returns 0 on successful execution, -1 otherwise.
 */
int main(int argc, char* argv[]) {
    // main args checking.
    if (argc != 4) {
        cerr << "Usage: Client IP PUERTO ID\n";
        return -1;
    }

    // Initialize C5Client with the provided IP and port.
    C5Client client(argv[1], atoi(argv[2]));
    client.setXmlFile("Xmlfile.xml"); // Set the XML file.

    // Create a user with the provided ID.
    C5User user(atoi(argv[3]));

    // Validate the user.
    XmlRpcValue validation;
    if (client.execute("userValidate", user.getId(), validation)) {
        if (int(validation) == 1) {
            C5CLI cli;
            // Start the cli interface loop on validation.
            if (cli.loop(client, user))
                return 0;
            else
                return -1;
        }
        cout << "Invalid user.\n";
        return 0;
    } else {
        cout << "Error validating user.\n";
        return -1;
    }
}
