#pragma once
using namespace std;
using ll = long long;
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
    ll Max_size() const{ return capacity; }
    ll Size() const{ return size; }
    void push(T value)
    {
        if (size == capacity) resize(capacity * 2);
        array[size] = value;
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
                    ll temp = array[j];
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
    bool Search(T value) const
    {
        ll left = 0;
        ll right = size - 1;
        while (left <= right)
        {
            if (array[left] == value || array[right] == value) return true;
            else {
                left++;
                right--;
            }
        }
        return false;
    }
    T Min()
    {
        if (size == 0) throw std::out_of_range("-1");
        T temp=array[0];
        
        for (ll i = 1; i < size; ++i)
        {
            if (array[i] < temp)temp = array[i];
        }
        
        return temp;

        // <..------ Neglected --------..>
        //ll left = 1;
        //ll right = size - 1;
        //while (left <= right)
        //{
        //    if(array[left]<temp) temp = array[left];
        //    if (array[right] < temp) temp = array[right];
        //    left++;
        //    right--;
        //}
    }
    T Max()
    {
        if (size == 0) throw std::out_of_range("-1");
        T temp = array[0];
        for (ll i = 1; i < size; ++i)
        {
            if (array[i] > temp)temp = array[i];
        }
            return temp;
    }

    void insert(ll indx,T value)
    {
        if (indx<0 || indx>size) throw std::out_of_range("-1");
        if (size == capacity) resize(capacity * 2);

        T temp = value;
        for (ll i = indx; i <= size; ++i)
        {
            T next=array[i];
            array[i] = temp;
            temp = next;
        }

        ++size;
    }

    T& operator[](ll i) const{ return array[i]; }
};