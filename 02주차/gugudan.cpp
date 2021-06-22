#include <iostream>

int main()
{
    int gugudan[8][9]={0};

    for (int i=0; i<8; i++)
    {
        for(int j=0; j<9; j++)
        {
            gugudan[i][j]=(i+2)*(j+1);
        }
    }

    for (int i=0; i<8; i++)
    {
        for(int j=0; j<9; j++)
        {
            std::cout << gugudan[i][j] << " ";
        }
        std::cout << std:: endl;
    }
    
    return 0;
}