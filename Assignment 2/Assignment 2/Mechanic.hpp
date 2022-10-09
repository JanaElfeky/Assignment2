//
//  Mechanic.hpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#ifndef Mechanic_hpp
#define Mechanic_hpp
#include <iostream>
#include <stdio.h>
#include "Person.h"
#include <vector>
using namespace std;

class mechanic:public person{
    int counter;
    vector<appointment> appts; //vector of type appointment to carry the mechanics' appointments 
public:
    mechanic();
    void printInfo();
    bool isAvailable(appointment userTime);
    void setCounter(int userCounter);
    void setAppts(mechanic mech, appointment userAppt);
    int getCounter();
    appointment getAppt(int index);
};



#endif /* Mechanic_hpp */
