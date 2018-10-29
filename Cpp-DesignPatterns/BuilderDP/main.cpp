#include <iostream>
#include <csignal>
#include <string>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <memory>

#include <boost/algorithm/string.hpp>
#include <sstream>
#include <vector>

//===============BUILDER DESIGN PATTERN===============
// String adapter
// most common when companies does not want to use STL or boost libraries or some like that
class String
{
        std::string s;
    public:
        String(const std::string &s) : s(s) {}

        String to_lower_copy() const
        {
            return { boost::to_lower_copy(this->s) };
        }

        // default value " "
        std::vector<String> split(const std::string& delimeter = " ") const
        {
            // a function to split our adapter String using boost
            std::vector<std::string> parts;
            // fulfill the vector with the actual s string but applying a cut in each time
            // the delimiter appears
            // token compress_on -> compress all repeated delimiters(witch are one next to the otherone etc)
            // in one single delimiter
            boost::split(parts, this->s, boost::is_any_of(delimeter), boost::token_compress_on);
            // returning a vector of same values as parts but with
            // our String adapter container
            return std::vector<String>(parts.begin(), parts.end());
        }

        size_t get_length() const
        {
            // deliver an interface for getting the length
            // of String
            return this->s.length();
        }
};

int main() {
    std::string s{"Hello     Worldy"};
    // THIS USUALLY LOOKS PRETTY BAD, SO WE CAN BUILD A STRING ADAPTER
    //=====================================================
    // using boost to make a lower case copy of s
    std::string sl = boost::to_lower_copy(s);

    std::cout << "string is: " << s << std::endl;
    std::cout << "string boost lower case is: " << sl << std::endl;

    // creating a stl vector
    std::vector<std::string> parts;

    //where to save splitted, what to split, case of split
    boost::split(parts, sl, boost::is_any_of(" "));

    for (auto& p : parts)
        // printing length of each part of the actual vector
        std::cout << p.length() << std::endl;
    //=====================================================

    std::cout << "Doing with Builder design pattern" << std::endl;
    // GOOD MANNER:
    // creating an instance of our addapter
    String s2{"Hello    World"};
    // applying the methods to get an splitted of lower case
    for(auto &w :s2.to_lower_copy().split())
        std::cout << w.get_length() << std::endl;

    return 0;
}