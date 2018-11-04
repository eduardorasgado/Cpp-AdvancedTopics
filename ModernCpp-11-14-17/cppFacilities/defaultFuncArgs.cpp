#include <iostream>
#define space() (std::cout << std::endl)

void CreateWindow(const char*, int, int, int, int);

// defining default to some  values as an option if not defined
// Default values should be always right side in parameters
void CreateWindow(const char* title, int x, int y, int width = 600, int height = 600)
{
    // printing the values
    std::cout << "Title: " << title << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "width: " << width << std::endl;
    std::cout << "height: "<< height << std::endl;
}

// this does not work
// x and width should be the last values to the right
//void CreateWindow(const char* title, int x = 150, int y, int width = 600, int height)

int main()
{
    //
    CreateWindow("Notepad", 150, 100, 500, 600);
    space();
    // with defalut values: not specifying some of the params
    // default values are alternatives we can skip, if we have 5 default values
    // we can skip 2, 4, or all the default values, it is not a must to skip all of them
    CreateWindow("Notepad", 150, 100);
    return 0;
}

