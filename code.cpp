#include <iostream>
using namespace std;

int main()
{
    int a = 1;
    ++ a = 3;
    cout << a << endl;
    (a ++) = 5;
    int &ref = 1;
    cout << a << endl;
    return 0;
}