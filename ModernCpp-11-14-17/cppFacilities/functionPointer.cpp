#include <iostream>
#include <initializer_list>
#include <vector>
#include <cstdlib>

// defining a simple \n macro
#define space() (std::cout << std::endl)

//------
// Functions to show how function pointer works
void Print(int, char);

double calculateAverage(std::vector<int>*);
//------

template <typename T, std::size_t N>
constexpr std::size_t returnSize(T(&)[N]) noexcept
{
    // returns length of whatever container
    return N;
}

// function called atexit() C special function
void EndMessage();


int main()
{
    // Function Pointer
    /*
     * Pointer that holds the address of the function
     * The type is same as the signature of the function (return type and arguments)
     * */

    // common way
    Print(5, '#');

    // function pointer
    // return_type name (args) = &addres_of_function
    void (*pfn)(int, char) =&Print;
    (*pfn)(5, '@');

    auto vector1 = new std::vector<int>();
    for(int i = 0;i < 10;++i) vector1->push_back(i);

    // function pointer to calculateAverage function
    double (*pfunc)(std::vector<int>*) = &calculateAverage;
    auto averageData = (*pfunc)(vector1);
    //printing the value we got from function pointer call
    std::cout << "Data: " << averageData << std::endl;

    //--------------------------some review--------------------
    // creating a initializer_list
    auto list01 = {1,2,3,4,5,6,7,8};
    std::initializer_list<int> list02{1,2,3,4,5,6,7,8};
    // creating a vector
    std::vector<int> list{1,2,3,4,5,6};
    // creating a simple build in array
    int testArr[] = {1,2,3,4,5,6,7,8,9};

    // printing all the lists and vector created above
    for(auto &v : list) std::cout << v << " ";
    space();
    for(auto &v : list01) std::cout << v << " ";
    space();
    for(auto &v : list02) std::cout << v << " ";
    space();

    //std::size_t (*pfunc) (T) = &returnSize;
    std::size_t sz = returnSize(testArr);
    std::cout << "Size: " << sz << std::endl;

    // creating and inserting values in vector
    auto vect = new std::vector<int>();
    for(int i = 0;i < 10;++i) vect->push_back(i);

    // getting size of the stl vector
    std::cout << vect->size() << std::endl;
    delete vect;
    //--------------------------end some review--------------------

    // In C: adexit reduce the function to a pointer, then
    // the function is executed at the end of main
    /*
     * Function to be called. The function shall return no value and take no arguments.
     *
     * If a function registered with atexit throws an exception for which it does not provide a handler
     * when called on termination, terminate is automatically called
     *
     * http://www.cplusplus.com/reference/cstdlib/atexit/
     * */
    atexit(EndMessage);

    std::cout << "END OF MAIN FUNCTION" << std::endl;
    delete vector1;
    return 0;
}

void Print(int count, char ch)
{
    // print some characters
    for(int i = 0;i < count;++i)
    {
        std::cout << ch;
        if(i ==(count-1)) std::cout << "\n";
    }
}

void EndMessage()
{
    // this is used in atexist() C function to be executed after main function finishes
    std::cout << "End of program" << std::endl;
}

double calculateAverage(std::vector<int>* v)
{
    double dd = 0.52225;
    std::cout << "Calculating average..." << std::endl;

    // creating an iterator for getting v[i]
    std::vector<int>::iterator i = v->begin();
    // using the iterator in a simple for loop
    // and adding values inside the vector to the return value
    for(i; i != v->end();++i) std::cout << *i << " ", dd+=*i;

    std::cout << std::endl;
    std::cout << "End calculating average..." << std::endl;

    return dd;
}