#include <iostream>

int main()
{
    int score[5] = {10, 30, 40, 60, 90};
    int sum = 0;

    for(int i=0; i<5; i++)
    {
        sum += score[i];
    }

    std::cout << sum << std::endl;

    return 0;
}