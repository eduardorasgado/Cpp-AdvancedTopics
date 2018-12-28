#include <iostream>
#include <memory>
// including main header to improve sockets
#include "restinio/all.hpp"

class miniServer {
private:
    int &port;
    std::string &address;
    std::string message;

public:
    miniServer(int &port, std::string &address)
    : port{port}, address{address}
    {
        std::cout << "[PARAMETROS LISTOS]" << std::endl;
    }

    void setMessage(const std::string &message) noexcept
    {
        this->message = message;
    }

    void runServer()
    {
        std::cout << "[SERVIDOR CORRIENDO]" << std::endl;
    }
};

int main()
{
    int port = 8080;
    std::string address = "localhost";
    std::string message = "[EL SERVIDOR SE ENCUENTRA ENCENDIDO A TRAVES DE UN SOCKET]";

    // creating our first server object
    auto simpleServer = std::make_unique<miniServer>(port, address);
    // setting the custom message
    simpleServer->setMessage(message);
    //
    simpleServer->runServer();

    return 0;
}