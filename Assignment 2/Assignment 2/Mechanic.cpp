//
//  Mechanic.cpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#include "Mechanic.hpp"
#include <iostream>
#include "Customer.hpp"
using namespace std;

mechanic::mechanic(){
    setCounter(0);
} //initializing mechanic class by setting the counter to 0
void mechanic::printInfo(){
    cout << "the mechanic's name is: " << getName() << " and their ID is: " << getID() << " and their age is: " << getAge() << " and the number of appointments they have for the day is: " << counter << endl;
} //displaying mechanic info
bool mechanic::isAvailable(appointment userTime){
    bool availability=true;
    for (int i=0;i<appts.size();i++){
        if (appts[i].hours==userTime.hours && appts[i].mins==userTime.mins)
            availability=false;
        else
            availability=true;
    } //looping through the mechanic's appointments to check if they are available at the specified time
    return availability;
}
void mechanic::setCounter(int userCounter){
    if (userCounter>=0) //validating counter isn't negative
        counter=userCounter; //setter for the counter
    else
        cout << "invalid counter, try again" << endl;
}
void mechanic::setAppts(mechanic mech, appointment userAppt){
        if (userAppt.hours>=0 && userAppt.hours<=23 && userAppt.mins>=0 && userAppt.mins<=59){ //validating that hours and mins are logical
            if (mech.isAvailable(userAppt)){
                appts.push_back(userAppt);
                counter++;
            }                   //adding the new appointment to the appts vector
            else
                cout << "current mechanic not available at this time" << endl;
        }
        else
            cout << "invalid appointment times, try again" << endl;
}
int mechanic::getCounter(){
    return counter; //getter for counter
}
person::appointment mechanic::getAppt(int index){
    if (index>=0 && index<appts.size()) //validating that the index is logical
        return appts[index]; //getter for the appointment
    else{
        cout << "invalid index, try again" << endl;
        exit(0);
    }
}
