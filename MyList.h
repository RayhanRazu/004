//
//  MyList.h
//  MyList
//
//  Created by Yevon Zhang on 17/2/14.
//  Copyright (c) 2017年 Yevon Zhang. All rights reserved.
//

#ifndef __MyList__MyList__
#define __MyList__MyList__

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;

class My_Out_of_Range_Exception:public std::out_of_range{
public:
    My_Out_of_Range_Exception():out_of_range("MyList [] out of range!"){}
};

template <typename T>
class MyList {
public:
    //function members
    MyList(int numVals = 0, T val = T()); // constructor
    MyList(const MyList<T> &il); // copy constructor
    ~MyList(); // destructor
    MyList<T>& operator=(const MyList<T> &il); // = operator
    int size() const; // size of the list
    int getCapacity() const;//capacity of the list
    // resize list
    void resize(int n = 0, T val = T());// resize list
    //reserver the capacity of size
    void reserve(int capacity);
    void push_back(T val); // add new last element
    std::string toString() const { //convert the list to string
        std::stringstream ss;
        ss<< this->numberValues;
        ss<< "("<<this->capacity<<")";
        ss<< ":";
        for (int i = 0; i < this->size(); ++i) {
            ss<< this->values[i] << " ";
        }
        return ss.str();
    }
    void print() const//print the list
    {
        std::cout<< this->toString();
        std::cout << std::endl;
    }
    T& operator [] ( const int index) throw (My_Out_of_Range_Exception);
    const T& operator [] ( const int index) const throw ( My_Out_of_Range_Exception );

private:
    // data members
    T* values; //pointer to elements
    int numberValues; //size of list
    int capacity;//capacity of list
};
template<typename T>
bool operator == (const MyList<T>& il1, const MyList<T>& il2);
template<typename T>
bool operator != (const MyList<T>& il1, const MyList<T>& il2);
template<typename T>
MyList<T> operator + (const MyList<T>& il1, const MyList<T>& il2);
template<typename T>
MyList<T> operator - (const MyList<T>& il1, const MyList<T>& il2);
template<typename T>
std::ostream& operator << (std::ostream& ost, const MyList<T>& il);
template<typename T>
std::istream& operator >> (std::istream& ist, MyList<T>& il);

#include "MyList.cpp"

#endif /* defined(__MyList__MyList__) */
