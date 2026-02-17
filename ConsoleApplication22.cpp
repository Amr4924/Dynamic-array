#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray x;
    int size = 0, index = 0;
    cout << "Size Input: ";
    cin >> size;
    cout << "--------------\n";
    while (size--)
    {
        int y = 0;
        cin >> y;
        x.push(y);
    }
    cout << "--------------\n";
    cout << "Print Output:-\n";
    while (true)
    {
        if (x.empty())break;
        cout << x[index] << " ";
        x.pop();
        index++;
    }

    return 0;
}