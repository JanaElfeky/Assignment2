//
//  Customer.cpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#include "Customer.hpp"
#include <iostream>
#include "Mechanic.hpp"
#include <vector>
using namespace std;

customer::customer(){
    //setMechID(""); //initializing customer
}
void customer::printInfo(){
    cout << "the customer's name is: " << getName() << " and their ID is: " << getID() << " and their age is: " << getAge() << " and their mechanic's ID is: " << mechID << " and their appointment is at: " << mechAppt.hours << " hours and " << mechAppt.mins << " minutes" << endl; //printing customer information
}
void customer::setMechID(string userMechID){
    if (userMechID=="1" || userMechID=="2" || userMechID=="3") //validating that mechanic ID isn't empty
        mechID=userMechID; //setter for mechanic ID
    else
        cout << "invalid mechanic ID, try again" << endl;
}
void customer::setMechAppt(appointment userMechAppt){
    if (userMechAppt.hours>=0 && userMechAppt.hours<=23 && userMechAppt.mins>=0 && userMechAppt.mins<=59){ //validating                                                                                   that the hours and mins are logical
        mechAppt.hours=userMechAppt.hours;
        mechAppt.mins=userMechAppt.mins;
    }
    else
        cout << "invalid appointment time, try again" << endl;
}
string customer::getMechID(){
    return mechID; //getter for mechanic ID
}
customer::appointment customer::getMechAppt(){
    return mechAppt; //getter for appointment
}
bool customer::operator>(const appointment &appt2){
    if (this->getMechAppt().hours>appt2.hours)
        return true;
    else if (this->getMechAppt().hours==appt2.hours){
        if (this->getMechAppt().mins>appt2.mins)
            return true;
        else
            return false;
    } //overloading the > operator to check which appointment is earlier
    else
        return false;
}
bool customer::operator<(const appointment &appt2){
    if (this->getMechAppt().hours<appt2.hours)
        return true;
    else if (this->getMechAppt().hours==appt2.hours){
        if (this->getMechAppt().mins<appt2.mins)
            return true;
        else
            return false;
    } //overloading the < operator to check which appointment is later
    else
        return false;
}
bool customer::operator==(const appointment &appt2){
    if (this->getMechAppt().hours==appt2.hours && this->getMechAppt().mins==appt2.mins)
        return true;
    else
        return false;
} //overloading the == operator to check if two appointments are at the same time
