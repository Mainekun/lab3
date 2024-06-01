#include <iostream>

/*

    [ ] Doesn't work range based loop
    >
    >   for ( auto i : MyArray) { ... }
    >
    
*/
template <typename data_type>
class MyArray
{
    size_t _n;
    data_type* _array;

public:
    MyArray(size_t n) : _n(n)
    { 
        _array = new data_type[_n];
    }
    MyArray() : _n(0) {}

    struct MyArrayIterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using T = data_type;
        using T_ptr = data_type*;
        using T_ref = data_type&;

        MyArrayIterator(T_ptr ptr) : _array_ptr(ptr) {}

        T_ref operator*() const { return *_array_ptr; }
        T_ptr operator->() { return _array_ptr; }

        MyArrayIterator& operator++() { _array_ptr++; return *this; }
        MyArrayIterator operator++(int) { MyArrayIterator temp = *this; ++(*this); return temp; }

        friend bool operator==(const MyArrayIterator& a, const MyArrayIterator& b)
            { return a._array_ptr == b._array_ptr; }
        friend bool operator!=(const MyArrayIterator& a, const MyArrayIterator& b)
            { return a._array_ptr != b._array_ptr; }
        
    private:
        T_ptr _array_ptr;
    };

    MyArrayIterator begin() { return MyArrayIterator( &_array[0]); }
    MyArrayIterator end() { return MyArrayIterator( &_array[_n]); }

};

int main()
{
    MyArray<int> arr(10);
    //std::fill(arr.begin(), arr.end(), 1);

    for (auto i : arr) printf("%d\t", i);
}