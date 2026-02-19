#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray<long long> array;
    int indx = 0;

    array.push(10);
    array.push(20);
    array.push(30);
    array.push(40);
    array.push(50);

    int s = *array.begin();
    int e = *array.end();

    cout << "First element: " << s << endl;
    cout << "Last element: " << s << endl;

    cout << "--------------------------\n";

    cout << "array elements : ";
    for (auto i = array.begin(); i < array.end(); ++i)
    {
        cout << *i << " ";
    }
    array.remove(30);
    cout << "\n--------------------------\n";

    cout << "Array elements after deletion : ";
    for (auto i = array.begin(); i < array.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n--------------------------\n";
    cout << "The array elements after deletion of 3 elements : ";
    array.erase(2);
    for (auto i = array.begin(); i < array.end(); ++i)
    {
        cout << *i << " ";
    }



    
    return 0;
}