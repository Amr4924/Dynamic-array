#pragma once
using namespace std;

class clsDynamicArray
{
private:
    int capacity;
    int size;
    int* array;
    static int defult_capacity() { return 8000; }
    void resize(int newcap)
    {
        int* newarray = new int[newcap];
        for (int i = 0; i < size; ++i) newarray[i] = array[i];
        delete[]array;
        array = newarray;
        capacity = newcap;
    }
public:
    clsDynamicArray() :capacity(defult_capacity()), size(0), array(new int[capacity]) {}
    clsDynamicArray(int cap) :capacity(cap > 0 ? cap : defult_capacity()), size(0), array(new int[capacity]) {}

    ~clsDynamicArray()
    {
        delete[]array;
    }
    int Front()const
    {
        if (size == 0)return -1;
        return array[0];
    }
    int Back()const
    {
        if (size == 0)return -1;
        return array[size-1];
    }
    int Max() const{ return capacity; }
    void push(int num)
    {
        if (size == capacity) resize(capacity * 2);
        array[size] = num;
        size++;
    }
    bool pop()
    {
        if (size == 0)return false;
        size--;
        return true;
    }
    bool empty() const { return size == 0; }
    


    int operator[](int i) const{ return array[i]; }
};