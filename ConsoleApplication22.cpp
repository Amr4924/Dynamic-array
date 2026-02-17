#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray <long long> array;
   
    long long size = 0;
    cout << "Size Input: ";
    cin >> size;
    cout << "--------------\n";
    while (size--)
    {
        long long y ;
        cin >> y;
        array.push(y);
    }

    cout << "--------------\n";
    cout << "Print Front and Back and Max Capacity:-\n";

	cout << "Front: " << array.Front() << "\n";
	cout << "Back: " << array.Back() << "\n";
	cout << "Max Capacity: " << array.Max() << "\n";

    cout << "--------------\n";
    cout << "Print in ascending order:-\n";
    array.Sort();

    for (long long i = 0; i < array.Size(); ++i)
    {
        cout << array[i]<<" ";
    }
    cout << "\n";

    cout << "Print in descending order:-\n";
    array.rSort();
    for (long long i = 0; i < array.Size(); ++i)
    {
        cout << array[i] << " ";
    }
    cout << "\n--------------\n";
    //Clear all elements of the array
    array.clear();

    cout << "Checking that the array is empty:-\n";

	if (array.empty()) cout << "Array is empty\n";
    
    array.~clsDynamicArray();
    return 0;
}