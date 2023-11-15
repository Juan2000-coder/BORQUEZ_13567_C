#ifndef _C5CLIENT_H
#define _C5CLIENT_H

#include "XmlRpc.h"
#include <string>
#include <fstream>

using namespace XmlRpc;

/**
 * @brief Inheritance specifically designed to override the parseResponse method
 * in the base class to dump the responses in XML format to a file.
 */
class C5Client : public XmlRpcClient {
public:
    using XmlRpcClient::XmlRpcClient;

    /**
     * @brief Same implementation in base class.
     * But also dumps the response in XML format to the Xmlfile.
     */
    bool parseResponse(XmlRpcValue& result) override;

    /**
     * @brief Sets the file to which the XML responses will be dumped.
     * @param file The name of the XML file.
     */
    void setXmlFile(std::string file);

    /**
     * @brief Dumps the content to XmlFile.
     *
     * Dumps the content of the response.
     *
     * @param file The path to the file where the content will be dumped.
     * @return True if the dump operation is successful, false otherwise.
     */
    bool dumToFile(std::string response);

private:
    std::string XmlFile; /**< The path to the XML file  */
};

#endif
