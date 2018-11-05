#include <iostream>
#include <cstdlib>

void TwoD()
{
    // creating a dynamic 2d array

    // creating array for columns
//    int *p1 = new int[3];
//    int *p2 = new int[3];

    // creating a container for those columns
    // in this case the rows
//    int **pData = new int *[2];

//    pData[0] = p1;
//    pData[1] = p2;

    // another way to create the 2d arr
    // two rows
    int **pData = new int *[2];

    // adding the 3 columns for each row though a for loop
    for (int l = 0; l < 2; ++l) {
        *(pData+l) = new int[3];
    }

    // now we can access as easy as when traditional array is created
    // introducing values to array
    int counter = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            *(*(pData+i)+j) = counter;
            counter++;
        }
    }
    std::cout << "Showing the 2D dynamic array: " << std::endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << *(*(pData+i)+j) << " ";

        }
        std::cout << "\n";
    }
    std::cout << pData[0][1] << std::endl;

    // deallocation
    // first: deallocating pointers inside the main container pointer
    for (int k = 0; k < 2; ++k) {
        delete pData[k];
    }
    // second: deallocating the main container
    delete []pData;
}

int main()
{
    // Allocating memory for 2D arrays

    // traditional array creation
    // rows, columns
    int data[2][3] = {{1,2,3}, {4,5,6}};
    std::cout << data[0][1] << std::endl;

    TwoD();

    return 0;
}