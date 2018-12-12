#include <iostream>
#include "boost/regex.hpp"
#include <cstring>
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"

int main() {
    std::cout << "[CLION AND CONAN TESTING]" << std::endl;
    Poco::MD5Engine md5;
    md5.update("Hello World");
    std::string md5string = Poco::DigestEngine::digestToHex(md5.digest());
    std::cout << "MD5: " << md5string << "\n";

    std::string s = "correct@email.com";
    std::string s2 = "bademail";

    static const boost::regex e{"\\b[a-zA-Z0-9._%-]+@[a-zA-Z0-9._]+\\.[a-zA-Z]{2,4}\\b"};

    auto compr1 = boost::regex_match(s, e);
    auto compr2 = boost::regex_match(s2, e);

    std::cout << "[IS AN EMAIL?]" << std::endl;

    std::cout << s << ", is an email: ";
    std::cout << std::boolalpha << compr1 << std::endl;
    std::cout << s2 << ", is an email: ";
    std::cout << std::boolalpha << compr2 << std::endl;
    return 0;
}