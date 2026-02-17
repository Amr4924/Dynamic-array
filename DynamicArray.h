#pragma once
using namespace std;
#define ll long long

template<typename T>
class clsDynamicArray
{
private:
    ll capacity;
    ll size;
    T* array;
    static ll defult_capacity() { return 45555; }
    void resize(ll newcap)
    {
        T* newarray = new T[newcap];
        for (ll i = 0; i < size; ++i) newarray[i] = array[i];
        delete[]array;
        array = newarray;
        capacity = newcap;
    }
public:
    clsDynamicArray() :capacity(defult_capacity()), size(0), array(new T[capacity]) {}
    clsDynamicArray(ll cap) :capacity(cap > 0 ? cap : defult_capacity()), size(0), array(new T[capacity]) {}

    ~clsDynamicArray()
    {
        delete[]array;
    }
    T& Front()const
    {
        if (size == 0)throw std::out_of_range("-1");
        return array[0];
    }
    T& Back()const
    {
        if (size == 0) throw std::out_of_range("-1");
        return array[size-1];
    }
    ll Max() const{ return capacity; }
    ll Size() const{ return size; }
    void push(T num)
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
    void clear() { size = 0; }
    void Sort()
    {
        for (ll i = 0; i < size - 1; ++i)
        {
            for (ll j = 0; j < size - i - 1; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }
    void rSort()
    {
        for (ll i = 0; i < size - 1; ++i)
        {
            for (ll j = 0; j < size - i - 1; ++j)
            {
                if (array[j] < array[j + 1])
                {
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    T& operator[](ll i) const{ return array[i]; }
};