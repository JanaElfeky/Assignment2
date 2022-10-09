//
//  Customer.hpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#ifndef Customer_hpp
#define Customer_hpp
#include <iostream>
#include <stdio.h>
#include "Person.h"
using namespace std;

class customer:public person{
    string mechID;
    appointment mechAppt; 
public:
    customer();
    void printInfo();
    void setMechID(string userMechID);
    void setMechAppt(appointment userMechAppt);
    string getMechID();
    appointment getMechAppt();
    bool operator > (const appointment &appt2);
    bool operator < (const appointment &appt2);
    bool operator == (const appointment &appt2);
};

#endif /* Customer_hpp */
