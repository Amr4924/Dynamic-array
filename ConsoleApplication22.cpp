#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray <long long> array;

    array.insert(0, 10);
    array.insert(1, 20);
    array.insert(2, 30);
    array.insert(3, 40);
    array.insert(4, 50);

    for (int i = 0; i < array.Size(); ++i)
    {
        cout << array[i] << " ";
    }
    cout << "\n-------------------\n";
    // Function Min and Max

    cout<<"Max number: " << array.Max() << endl;
    cout<<"Min number: " << array.Min() << endl;

    // Search
    if (array.Search(30))
    {
        cout << "number: " << 30 << endl;
    }

    return 0;
}