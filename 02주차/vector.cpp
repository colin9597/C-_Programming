#include <iostream>
#include <vector>
using namespace std;
int main()
{
    /*vector<int> values{1, 2, 3, 4, 5};

    for (auto n : values)
        cout << n << ' ';
    cout << '\n';

    cout << "Range-based for over brace-init-list: \n";
    for (int x: {-1, -2, -3})
        cout << x << ' ';
    cout << '\n';

    auto al = {10, 11, 12};
    cout << "The list bound to auto has size() = " << al.size() << '\n';*/
    
    vector<int> vint(5);
    for (vector<int>::iterator it =vint.begin(); it != vint.end(); ++it)
    {
        *it=20;
        cout << *it << '\t';
    }
    cout << endl;
    cout << vint[3] << endl;
   
    return 0;

}