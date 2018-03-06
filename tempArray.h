#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array {
private:
    int m_nLength;
    T * m_ptData;
    
public:
    Array() {
        m_nLength = 0;
        m_ptData = 0;
    }
    
    Array(int nLength) {
        m_ptData = new T[nLength];
        m_nLength = nLength;
    }
    
    ~Array() {
        delete[] m_ptData;
    }
    
    void Erase() {
        delete[] m_ptData; // We need to make sure we set m_pnData to 0 here, otherwise it will
        // be left pointing at deallocated memory
        m_ptData = 0;
        m_nLength = 0;
    }
    
    T& operator[](int nIndex) {
        if (nIndex >= 0 && nIndex < m_nLength)
            return m_ptData[nIndex];
    }// The length of the array is always an integer
    // It does not depend on the data type of the arrayint GetLength();
    // templated GetLength() function defined below
    
    T* getArrPtr() const
    {
        return m_ptData;
    }
    
    int GetLength() const
    {
        return m_nLength;
    }
    
    Array<T>& operator=(const Array<T>& a) {
        if (this == &a)
            return *this;
        delete[] data;
        
        size_ = a.size();
        data = new T(size_);
        copy(&a.data[0], &a.data[a.size()], data);
        
        return *this;
    }
};
