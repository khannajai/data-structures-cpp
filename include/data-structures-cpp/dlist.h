#include <iostream>
#include <exception>

template <class T>
class dnode
{
    public:
    T data;
    dnode* next;
    dnode* previous;
    dnode(const T& x=T(), dnode * n=nullptr, dnode * p = nullptr): data(x),next(n),previous(p){};
    ~dnode(){}; 
};

class invalidIndex:public std::exception
{
    public:
    const char * what() const throw()
    {
        return "attempting to access invalid index";
    };

};

class memError:public std::exception
{
    public:
    const char * what() const throw()
    {
        return "error allocating memory";
    };
};

template <class T>
class dlist
{
    private:
    dnode<T>* start;
    dnode<T>* end;
    int size;
    
    public:
    //constructors and destructor
    dlist(void);
    dlist(const dlist<T>&);
    ~dlist();

    bool insert_front(const T&);
    bool insert_back(const T&);
    bool insert(const T&, const int&);
    
    bool remove_front(void);
    bool remove_back(void);
    bool remove(const int&);
    
    T show_front(void) const;
    T show_back(void) const;
    T operator[](const int&) const;

    template <class U>
    friend std::ostream& operator<<(std::ostream&, const dlist<U>&);

    int length() const;
    void clear(void);
};

template <class T>
dlist<T>::dlist(void)
{
    start=new dnode<T>();
    end=new dnode<T>();
    size=0;
}

template <class T>
dlist<T>::dlist(const dlist<T>& other)
{
    start=new dnode<T>();
    end=new dnode<T>();
    size=0;
    for(int i=0;i<other.size;i++)
    {
        insert_back(other[i]);
    }
}

template <class T>
dlist<T>::~dlist()
{
    clear();
}

template <class T>
void dlist<T>::clear(void)
{   
    dnode<T>* current=start;
    for(int i=0;i<size;i++)
    {
        delete current;
        current=current->next;
    }
}

template <class T>
bool dlist<T>::insert_front(const T& el)
{
    dnode<T> * new_node=new dnode<T>();
    if(new_node==nullptr)
    {
        throw memError();
        return 0;
    }
    new_node->data=el;
    new_node->next=start;
    new_node->previous=nullptr;
    start->previous=new_node;
    start=new_node;
    size++;
    if(size==1)
    {
        end=start;
    }
    return 1;
}

template <class T>
bool dlist<T>::insert_back(const T& el)
{
    dnode<T>* new_node = new dnode<T>();
    if(new_node==nullptr)
    {
        throw memError();
        return 0;
    }
    new_node->data=el;
    new_node->previous=end;
    new_node->next=nullptr;
    end->next=new_node;
    end=new_node;
    size++;
    if(size==1)
    {
        start=end;
    }
    return 1;
}


template <class T>
bool dlist<T>::insert(const T& el, const int& pos)
{
    dnode<T>* new_node = new dnode<T>();
    if(new_node==nullptr)
    {
        throw memError();
        return 0;
    }
    if(pos>size || pos<0)
    {
        throw invalidIndex();
        return 0;
    }
    if(pos==0)
    {
        insert_front(el);
        return 1;
    }
    else if(pos==size)
    {
        insert_back(el);
        return 1;
    }
    else
    {
        dnode<T>* before;
        dnode<T>* after;
        dnode<T>* current;
        if(pos<size-1-pos)
        {
            current=start;
            for(int i=0;i<pos;i++)
            {
                current=current->next;
            }
            before=current->previous;
            after=current;
            new_node->previous=before;
            new_node->next=after;
            after->previous=new_node;
            before->next=new_node;
            new_node->data=el;
            size++;
            return 1;
        }
        else
        {
            current=end;
            for(int i=0;i<size-1-pos;i++)
            {
                current=current->previous;
                std::cout<<i<<" ";
            }
            std::cout<<std::endl;
                before=current->previous;
                after=current;
                new_node->previous=before;
                new_node->next=after;
                after->previous=new_node;
                before->next=new_node;
                new_node->data=el;
                size++;
                return 1;
        }
    }
    
}

template <class T>
T dlist<T>::operator[](const int& pos) const
{
    if(pos>=size || pos<0)
    {
        throw invalidIndex();
        return 0;
    }
    dnode<T>* current;
    if(size-1-pos>pos)
    {
        current=start;
        for(int i=0;i<pos;i++)
        {
            current=current->next;
        }
        return current->data;
    }
    else
    {
        current=end;
        for(int i=0;i<size-1-pos;i++)
        {
            current=current->previous;
        }
        return current->data;
    }

}

template <class T>
bool dlist<T>::remove_front(void)
{
    if(size==0)
    {
        std::cout<<"Nothing to remove"<<std::endl;
        return 0;
    }
    dnode<T>* new_start=start->next;
    delete start;
    start=new_start;
    size--;
    return 1;
}

template <class T>
bool dlist<T>::remove_back(void)
{
    if(size==0)
    {
        std::cout<<"Nothing to remove"<<std::endl;
        return 0;
    }
    dnode<T>* new_end=end->previous;
    delete end;
    end=new_end;
    size--;
    return 1;
}

template <class T>
bool dlist<T>::remove(const int& pos)
{
    if(size==0)
    {
        std::cout<<"Nothing to remove"<<std::endl;
        return 0;
    }
    
    if(pos>=size || pos<0)
    {
        throw invalidIndex();
    }

    if(pos==0)
    {
        remove_front();
        return 1;
    }

    else if(pos==size-1)
    {
        remove_back();
        return 1;
    }

    dnode<T>* before;
    dnode<T>* after;
    dnode<T>* current;
    if(pos<size-1-pos)
    {
        current=start;
        for(int i=0;i<pos;i++)
        {
            current=current->next;
        }
        before=current->previous;
        after=current->next;
        before->next=after;
        after->previous=before;
        size--;
        return 1;
    }
    else
    {
        current=end;
        for(int i=0;i<size-1-pos;i++)
        {
            current=current->previous;
        }
            before=current->previous;
            after=current;
            before->next=after;
            after->previous=before;
            size--;
            return 1;
    }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const dlist<T>& my_list)
{
    for(int i=0;i<my_list.size;i++)
    {
        out<<my_list[i]<<'\t';
    }
    return out;
}

template <class T>
int dlist<T>::length(void) const
{
    return size;
}

template <class T>
T dlist<T>::show_front(void) const
{
    return start->data;
}

template <class T>
T dlist<T>::show_back(void) const
{
    return end->data;
}