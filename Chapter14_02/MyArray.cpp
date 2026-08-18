#include "MyArray.h"

template<typename T>
void MyArray<T>::print() const
{
    for (int i = 0; i < m_length; ++i)
        std::cout << m_data[i] << " ";
    std::cout << std::endl;
}

// explicit instantiaion
template class MyArray<char>;
template class MyArray<double>;
template class MyArray<int>;

//template void MyArray<char>::print() const;
//template void MyArray<int>::print() const;