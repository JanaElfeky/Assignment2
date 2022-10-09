//
//  Person.h
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#ifndef Person_h
#define Person_h
#include <iostream>
using namespace std;

class person{
    string name;
    string ID;
    int age;
public:
    void setName(string userName);
    void setID(string userID);
    void setAge(int userAge);
    string getName();
    string getID();
    int getAge();
    virtual void printInfo()=0;
    struct appointment{
        int hours;
        int mins;
    }; //struct for the appointments
};


#endif /* Person_h */
