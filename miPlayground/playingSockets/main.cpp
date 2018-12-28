#include <iostream>
#include <memory>
#include <fstream> // readi files
// including main header to improve sockets
#include "restinio/all.hpp"

class miniServer {
private:
    u_int16_t &port;
    std::string &address;
    std::string message;
    static std::string HTML;

public:
    miniServer(u_int16_t &port, std::string &address)
    : port{port}, address{address}
    {
        std::cout << "[PARAMETROS LISTOS]" << std::endl;
    }

    void runServer()
    {
        std::cout << "[SERVIDOR CORRIENDO]" << std::endl;
        restinio::run(restinio::on_this_thread().port(this->port).address(this->address)
        .request_handler(internalHandler));
    }

    void setMessage(const std::string &message) noexcept
    {
        this->message = message;
    }

    static restinio::request_handling_status_t internalHandler(
            const restinio::request_handle_t& request)
    {
        if(restinio::http_method_get() == request->header().method() &&
        request->header().request_target() == "/")
        {
            request->create_response()
            .append_header(restinio::http_field::server, "[SIMPLE CUSTOM SERVER]")
            .append_header_date_field()
            .append_header(restinio::http_field::content_type, "text/html; charset=utf-8")
            .set_body(HTML)
            //.set_body("[FRONTEND]")
            .done();

            return restinio::request_accepted();
        }
        return restinio::request_rejected();
    }

};

auto fileReader() noexcept
{
    std::string webContent = "";
    try {
        std::ifstream infile;
        infile.open("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/miPlayground/playingSockets/frontend.txt");

        if(infile.good() && infile.is_open())
        {
            std::string line;
            while(!infile.eof()) // end of file
            {
                // saving the actual line and adding into the global string
                std::getline(infile, line);
                webContent += line;
            }
        }
        infile.close();
    } catch(std::exception& e)
    {
        std::cout << "ERROR" << std::endl;
    }
    // returning the text inside the file
    return webContent;
}


//INSECURE WAY->no handler for errors
auto content = fileReader();
std::string miniServer::HTML = content;

int main()
{
    // see https://stiffstream.com/en/docs/restinio/0.4/gettingstarted.html#enhance-request-handler
    u_int16_t port = 8080;
    std::string address = "localhost";
    std::string message = "[EL SERVIDOR SE ENCUENTRA ENCENDIDO A TRAVES DE UN SOCKET]";

    // creating our first server object
    auto simpleServer = std::make_unique<miniServer>(port, address);
    // setting the custom message
    //simpleServer->setMessage(message);

    simpleServer->runServer();



    return 0;
}