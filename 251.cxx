/*
    Not finished.
*/

#include <iostream>
#include <fstream>

using namespace std;

class IntegerArray
{
    size_t n;
    int* arr;

public:
    struct Iterator
    {
        using iterator_category = random_access_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_t = int;
        using pointer = int*;
        using reference = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() { return *m_ptr; }
        pointer operator->() { return m_ptr; }

        Iterator& operator++() { m_ptr++; return *this; }
        Iterator& operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        Iterator& operator+=(int x) { m_ptr += x; return *this; }
        //operator+

        Iterator& operator--() { m_ptr--; return *this; }
        Iterator& operator--(int) { Iterator temp = *this; --(*this); return temp; }
        Iterator& operator-=(int x) { m_ptr -= x; return *this; }
        //operator-

        friend bool operator== (const Iterator a, const Iterator b) { return a.m_ptr == b.m_ptr; }
        friend bool operator!= (const Iterator a, const Iterator b) { return a.m_ptr != b.m_ptr; }
        friend bool operator< (const Iterator a, const Iterator b) { return a.m_ptr < b.m_ptr; }
        friend bool operator> (const Iterator a, const Iterator b) { return a.m_ptr > b.m_ptr; }
        //...

    private:
        pointer m_ptr;
    };

    IntegerArray(size_t _n) : n(_n)
    {
        arr = new int[n];
    }
    IntegerArray(){}

    inline size_t size() { return n; }



};

int main()
{

}