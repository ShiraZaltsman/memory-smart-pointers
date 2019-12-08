//
// Created by shira on 12/8/19.
//

#ifndef MEMORY_SMART_POINTERS_SHIRAZALTSMAN_SHEREPTR_H
#define MEMORY_SMART_POINTERS_SHIRAZALTSMAN_SHEREPTR_H
#include <iostream>
using namespace std;

template< class T >
class SharedPtr {
public:
    // Constructor
    explicit SharedPtr(T* ptr = NULL);
    // Copy constructor
    SharedPtr(SharedPtr<T>& sp);

    // Reference count
    unsigned int use_count();

    // Get the pointer
    T* get();

    // Destructor
    ~SharedPtr();

    T& operator=( const SharedPtr& ptr );
    T* operator->( ) { return m_ptr; }
    T& operator*() { return *m_ptr; }
    //operator bool() const;



private:
    // Reference counter
    unsigned int m_counter;

    // Shared pointer
    T* m_ptr;

};

template<class T>
inline SharedPtr<T>::SharedPtr(T *ptr) {
    m_counter = 0;
    m_ptr=ptr;
    if (ptr) {
        m_counter++;
    }
}

template<class T>
inline unsigned int SharedPtr<T>::use_count(){
    return m_counter;
}

template<class T>
inline SharedPtr<T>::SharedPtr(SharedPtr<T> &sp){
    m_ptr = sp.m_ptr;
    m_counter = sp.m_counter;
    m_counter++;
}

template<class T>
T& SharedPtr<T>::operator=( const SharedPtr& ptr )
{
    m_ptr = ptr.m_ptr;
    ptr.m_counter++;
    m_counter = ptr.m_counter;
    return *this;
}

template<class T>
inline SharedPtr<T>::~SharedPtr()     {
    m_counter--;
    if (m_counter == 0) {
        delete m_counter;
        delete m_ptr;
    }
}

template<class T>
T *SharedPtr<T>::get()     {
    return m_ptr;
}

#endif //MEMORY_SMART_POINTERS_SHIRAZALTSMAN_SHEREPTR_H
