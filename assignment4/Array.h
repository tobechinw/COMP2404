#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Photo.h"

using namespace std;

template <class T>
class Array {


	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(T);
		void remove(T);
        Array<T>& operator+=(const T&);
        Array<T>& operator-=(const T&);
        T& operator[](int) const;
		int size() const;
        void clear();
		bool isFull() const;

	private:
		int numElements;
		T* elements;

};

template <class T>
Array<T>& Array<T>::operator+=(const T& elem){
    if(numElements < MAX_ARRAY){
        elements[numElements++] = elem;
    }

    return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(const T& elem){

    for(int i = 0; i < numElements; ++i){
        if(elements[i] == elem){
            for(int j = i; j < numElements - 1; ++j){
                elements[j] = elements[j + 1];
            }
            numElements--;
            break;
        }
    }

    return *this;
}


template <class T>
Array<T>::Array(){
    elements = new T[MAX_ARRAY];
    numElements = 0;
}


template <class T>
Array<T>::~Array(){
    delete [] elements;
}


template <class T>
void Array<T>::add(T t){
    if (isFull())   return;
    elements[numElements++] = t;
}


template <class T>
void Array<T>::remove(T t){
    int index = 0;
    while (index < numElements){
        if (t == elements[index]){
            --numElements;
            break;
        }
        ++index;
    }

    while (index < numElements){
        elements[index] = elements[index + 1];
        ++index;
    }
}



template <class T>
int Array<T>::size() const{
    return numElements;
}


template <class T>
void Array<T>::clear() {
    numElements = 0;
}

template <class T>
bool Array<T>::isFull() const {
    return numElements >= MAX_ARRAY;
}

template <class T>
T& Array<T>::operator[](int index) const{
    if (index < 0 || index >= numElements) {
        cerr<<"Array index out of bounds"<<endl;
        exit(1);
    }
    return elements[index];
}





#endif


