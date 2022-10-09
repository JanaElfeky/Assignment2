//
//  Person.cpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#include <stdio.h>
#include "Person.h"
#include <iostream>
using namespace std;

void person::setName(string userName){
    if (userName!="") //validating that the name isn't empty
        name=userName;
    else
        cout << "invalid name, try again" << endl; //setter for the person's name
}
void person::setID(string userID){
    if (userID!="") //validating that the ID isn't empty
        ID=userID;
    else
        cout << "invalid ID, try again" << endl;
} //setter for the person's ID
void person::setAge(int userAge){
    if (userAge>=0) //validating that the age isn't negative
        age=userAge;
    else
        cout << "invalid age, try again" << endl;
} //setter for the person's age
string person::getName(){
    return name; //getter for the name
}
string person::getID(){
    return ID; //getter for the ID
}
int person::getAge(){
    return age; //getter for the age
}
