#pragma once
using namespace std;
using ll = long long;
template<typename T>

class clsDynamicArray
{
private:
    ll capacity;
    ll Size;
    T* array;
    static ll defult_capacity() { return 45555; }
    void resize(ll newcap)
    {
        T* newarray = new T[newcap];
        for (ll i = 0; i < Size; ++i) newarray[i] = array[i];
        delete[]array;
        array = newarray;
        capacity = newcap;
    }
public:
    clsDynamicArray() :capacity(defult_capacity()), Size(0), array(new T[capacity]) {}
    clsDynamicArray(ll cap) :capacity(cap > 0 ? cap : defult_capacity()), Size(0), array(new T[capacity]) {}

    ~clsDynamicArray()
    {
        delete[]array;
    }
    T& Front()const
    {
        if (Size == 0)throw std::out_of_range("-1");
        return array[0];
    }
    T& Back()const
    {
        if (Size == 0) throw std::out_of_range("-1");
        return array[Size-1];
    }
    ll Max_size() const{ return capacity; }
    ll size() const{ return Size; }
    void push(T value)
    {
        if (Size == capacity) resize(capacity * 2);
        array[Size] = value;
        Size++;
    }
    bool pop()
    {
        if (Size == 0)return false;
        Size--;
        return true;
    }
    inline bool empty() const { return Size == 0; }
    inline void clear() { Size = 0; }
    void Sort()
    {
        for (ll i = 0; i < Size - 1; ++i)
        {
            for (ll j = 0; j < Size - i - 1; ++j)
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
        for (ll i = 0; i < Size - 1; ++i)
        {
            for (ll j = 0; j < Size - i - 1; ++j)
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
        ll right = Size - 1;
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
        if (Size == 0) throw std::out_of_range("-1");
        T temp=array[0];
        
        for (ll i = 1; i < Size; ++i)
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
        if (Size == 0) throw std::out_of_range("-1");
        T temp = array[0];
        for (ll i = 1; i < Size; ++i)
        {
            if (array[i] > temp)temp = array[i];
        }
            return temp;
    }

    void insert(ll indx,T value)
    {
        if (indx<0 || indx>Size) throw std::out_of_range("-1");
        if (Size == capacity) resize(capacity * 2);

        T temp = value;
        for (ll i = indx; i <= Size; ++i)
        {
            T next=array[i];
            array[i] = temp;
            temp = next;
        }

        ++Size;
    }

    void erase(ll indx)
    {
        if (indx<0 || indx >= Size)throw std::out_of_range("-1");
        for (ll i = indx; i < Size; ++i)
        {
            array[i] = array[i + 1];
        }
        Size--;
    }

    inline T* begin() { return array; }
    inline T* end() { return (array + Size); }

    void remove(T value)
    {
        ll write = 0, read = 0;
        while (read <Size)
        {
            if (array[read] != value)
            {
                array[write] = array[read];
                write++;
            }
            read++;
        }
        Size = write;
    }



    T& operator[](ll i) const{ return array[i]; }
};