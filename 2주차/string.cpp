#include <iostream>
#include <string.h>

int main()
{
    /*char buffer[] = "Hello";

    for(int i=0; i<6; i++)
    {
        std::cout << buffer[i] << std::endl;
    }

    std::cout << buffer << std::endl;

    char buffer2[2]={0};
    strncpy(buffer2, buffer, 2);
    std::cout << buffer2 << std::endl;*/

    using namespace std;

    string s1 = "hello";
    string s2 = "world";

    string s= s1+s2;

    //cout << s << endl;

    char buffer[100]={0};

    cin.get(buffer, 99);

    s=buffer;
    cout << s;


    return 0;
}