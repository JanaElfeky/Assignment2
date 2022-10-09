//
//  Queue.hpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#ifndef Queue_hpp
#define Queue_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

template<class T>
class Queue{ //this circular queue will be implemented using arrays
    int first, last, size;
    T* array; //pointer of type T pointing to the queue array
public:
    Queue(int userSize);
    ~Queue();
    const void push(T input);
    const T pop();
};

template<class T>
Queue<T>::Queue(int userSize){
    first=last=-1;
    size=userSize;
    array=new T [size]; //initializing the empty queue array
}
template<class T>
Queue<T>::~Queue(){
    delete [] array; //deallocating dynamic array's memory
}
template<class T>
const void Queue<T>::push(T input){
    if (first==0 && last==size-1)
        cout << "the queue is full" << endl; //in case of full array
    else if (first==-1){
        first=last=0;
        array[last]=input; //in case of inputing first value in the queue
    }
    else if (last==size-1 && first!=0){
        last=0;
        array[last]=input; //in case  of the last element being full, but the first is empty
    }
    else{
        last++;
        array[last]=input; //in case of normal input
    }
}
template<class T>
const T Queue<T>::pop(){
    if (first==-1){
        cout << "this queue is empty" << endl;
        return (0); //in case of empty array
    }
    T output=array[first];
    if (first==last){
        first=last=-1; //in case of the array becoming empty
    }
    else if (first==size-1)
        first=0; //in case of the first element reaching the end of the queue
    else
        first++; //in case of normal output
    return output;
}

#endif /* Queue_hpp */
