#include <iostream>
#include <dlist.h>

template <class T>
class heap
{
    private:
    dlist<T> arr;
    int heapSize;
    int length;

    public:
    heap(void);
    heap(const dlist<T>&);
    heap(insert);
    
};