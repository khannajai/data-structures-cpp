#include <iostream>
#include <exception>

class stackOverUnderFlow:public std::exception
{
    private:
    bool errorType;
    
    public:
    stackOverUnderFlow(){};
    stackOverUnderFlow(bool overUnder);
    const char * what() const throw()
    {
        if (errorType==0)
        {
            return "stack underflow";
        }
        else 
        {
            return "stack overflow";
        }
    }
};

stackOverUnderFlow::stackOverUnderFlow(bool overUnder)
{
    this->errorType=overUnder;
}

template <typename T>
class stack
{
    private:
    T * arr;
    int maxSize;
    int size;

    public:
    stack(void);
    stack(int n);
    stack(const stack&);
    ~stack();
    bool push(T);
    bool pop(T&);
    T back(void) const;
    int getNumEntries();
    template <typename Y>
    friend std::ostream& operator<<(std::ostream&,const stack<Y>&);
};

template <typename T>
stack<T>::stack(void)
{
    maxSize=10;
    arr = new T[10];
    size=0;
}

template <typename T>
stack<T>::stack(int x)
{
    maxSize=x;
    arr = new T[maxSize];
    size=0;
}

template <typename T>
stack<T>::~stack()
{
    delete[] arr;
}

template <typename T>
stack<T>::stack(const stack<T>& other)
{
    size=other.size;
    maxSize=other.maxSize;
    arr=new T[maxSize];
    for (int i=0; i<size; i++)
    {
        arr[i]=other[i];
    }
}

template <typename T>
bool stack<T>::push(T el)
{
    std::cout<<size<<std::endl;
    if (size>=maxSize)
    {
        throw stackOverUnderFlow(1);
    }
    else
    {
        arr[size]=el;
        size++;
        std::cout<<"pushed element"<<std::endl;
        return 1;
    }
}

template <typename T>
bool stack<T>::pop(T& el)
{
    if (size<=0)
    {
        throw stackOverUnderFlow(0);
        return 0;
    }
    else
    {
        size--;
        el=arr[size];
        return 1;
    }
}

template <typename T>
T stack<T>::back(void) const
{
    return arr[size-1];
}

template <typename T>
int stack<T>::getNumEntries()
{
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const stack<T>& x)
{
    for (int i=0;i<x.size;i++)
    {
        out<<(x.arr)[i]<<"\t";
    }
    out<<std::endl;
    return out;
}