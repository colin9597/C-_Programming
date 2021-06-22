#include <iostream>

int main()
{
    int myArray[5];
    int i;
    for (i=0; i<5; i++)
    {
        std::cout << "Value for myArray[" << i << "]: ";
        std::cint >> myArray[i];
    }
    for (i=0; i<5; i++)
        std::cout << i << ": " << myArray[i] << std::endl;
    return 0;
}