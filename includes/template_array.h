//
// Created by gerdon on 22.12.17.
//

#ifndef SORT_TEMPLATE_ARRAY_H
#define SORT_TEMPLATE_ARRAY_H

#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <typeinfo>


template< typename T > class T_array {

public:
    T_array() = delete;
    T_array (size_t s) {
        size = s;
        myarray = new T [size];
    }

    void setArray ( int elem, T val) {
        myarray[elem] = val;
    }
    void generateArray(int){cout <<"unpredictable behavior, an explicit definition is required";}
    T* getArray_(){return myarray;};

    void getArray () {
        for ( int j = 0; j < size; j++ ) {
            cout << setw( 7 ) << j+1 << setw( 13 ) << myarray[ j ]
                 << " type: " << typeid(myarray[ j ]).name() << endl;
        }
        cout << "-----------------------------" << endl;
    }
    ~T_array(){
        delete[] myarray;
    }

    size_t getSize(){ return size;}
private:
    size_t size;
    T *myarray;
};



template <>
void T_array<std::string>::generateArray (int length) {
    static const char alphanum[] =
            "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";


        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < length; ++j) {
                myarray[i] = myarray[i] + alphanum[rand() % (sizeof(alphanum) - 1)];
            }
        }
}

#endif
#endif //SORT_TEMPLATE_ARRAY_H
