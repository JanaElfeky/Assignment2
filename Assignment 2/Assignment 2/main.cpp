//
//  main.cpp
//  Assignment 2
//
//  Created by jana on 02/10/2022.
//

#include <iostream>
#include "Customer.hpp"
#include "Mechanic.hpp"
#include "Queue.hpp"
#include <fstream>
using namespace std;

void appointmentSetUp(mechanic mechArray[], customer custArray[]);
void print(customer custArray[], mechanic mechArray[]);

int main(int argc, const char * argv[]) {
    mechanic mech1, mech2, mech3; //initializing 3 mechanics
    customer cust1, cust2, cust3, cust4, cust5, cust6; //initializing 6 customers
    mechanic mechArr[3]={mech1, mech2, mech3}; //putting the mechanics in an array
    customer custArr[6]={cust1, cust2, cust3, cust4, cust5, cust6}; //putting the customers in an array
    
    cout << "please enter the three mechanics' names" << endl; //mechanic name input
    string mechName;
    for (int i=0;i<3;i++){
        cin >> mechName;
        mechArr[i].setName(mechName);
    }
    cout << "please enter the three mechanics' IDs" << endl; //mechanic ID input
    string mechID;
    for (int i=0;i<3;i++){
        cin >> mechID;
        mechArr[i].setID(mechID);
    }
    cout << "please enter the three mechanics' ages" << endl; //mechanic age input
    int mechAge;
    for (int i=0;i<3;i++){
        cin >> mechAge;
        mechArr[i].setAge(mechAge);
    }
    cout << "please enter the six customers' names" << endl; //customer name input
    string custName;
    for (int i=0;i<6;i++){
        cin >> custName;
        custArr[i].setName(custName);
    }
    cout << "please enter the six customers' IDs" << endl; //customer ID input
    string custID;
    for (int i=0;i<6;i++){
        cin >> custID;
        custArr[i].setID(custID);
    }
    cout << "please enter the six customers' ages" << endl; //customer age input
    int custAge;
    for (int i=0;i<6;i++){
        cin >> custAge;
        custArr[i].setAge(custAge);
    }
    cout << "please enter the six customers' appointments by hours then minutes" << endl; //customer appointment input
    customer::appointment custAppt;
    int hours, mins;
    for (int i=0;i<6;i++){
        cin >> hours >> mins;
        custAppt.hours=hours;
        custAppt.mins=mins;
        custArr[i].setMechAppt(custAppt);
    }
    
    appointmentSetUp(mechArr, custArr); //calling function to set customer to mechanic
    
    
    print(custArr, mechArr); //calling function to print customer and mechanic information
    
    Queue<customer> custQueue(6); //initializing a queue of type customer with 6 elements
        customer temp;
        for (int i=0;i<6;i++){
            for (int j=i;j<6;j++){
                if (custArr[i]>custArr[j+1].getMechAppt()){
                    temp=custArr[i];
                    custArr[i]=custArr[j+1];
                    custArr[j+1]=temp; //sorting the customer array in ascending order of appointments
                }
            }
        }
        for (int i=0;i<6;i++){
            custQueue.push(custArr[i]); //oushing the sorted array into the queue
        }
    
    
   
    return 0;
}

void appointmentSetUp(mechanic mechArray[], customer custArray[]){
    for (int i=0;i<3;i++){
            if (mechArray[i].isAvailable(custArray[i].getMechAppt())){
                mechArray[i].setAppts(mechArray[i],custArray[i].getMechAppt());
                custArray[i].setMechID(mechArray[i].getID());
            }
            else if (mechArray[i+1].isAvailable(custArray[i].getMechAppt())){
                     mechArray[i+1].setAppts(mechArray[i+1],custArray[i].getMechAppt());
                     custArray[i].setMechID(mechArray[i+1].getID());
            }
                    else if (mechArray[i+2].isAvailable(custArray[i].getMechAppt())){
                              mechArray[i+2].setAppts(mechArray[i+2],custArray[i].getMechAppt());
                              custArray[i].setMechID(mechArray[i+2].getID());
                    }
                              else
                                  cout << "no mechanic is available at the time requested for customer " << i << endl;
        
    }
            
    for (int i=3;i<6;i++){
            if (mechArray[i-3].isAvailable(custArray[i].getMechAppt())){
                mechArray[i-3].setAppts(mechArray[i-3], custArray[i].getMechAppt());
                custArray[i].setMechID(mechArray[i-3].getID());
            }
            else if (mechArray[i-2].isAvailable(custArray[i].getMechAppt())){
                     mechArray[i-2].setAppts(mechArray[i-2], custArray[i].getMechAppt());
                     custArray[i].setMechID(mechArray[i-2].getID());
            }
                    else if (mechArray[i-1].isAvailable(custArray[i].getMechAppt())){
                              mechArray[i-1].setAppts(mechArray[i-1], custArray[i].getMechAppt());
                              custArray[i].setMechID(mechArray[i-1].getID());
                    }
                              else
                                  cout << "no mechanic is available at the time requested for customer " << i << endl;
        }
}
    

void print(customer custArray[], mechanic mechArray[]){
    for (int i=0;i<6;i++){
        if (custArray[i].getMechID()=="1"){
            cout << custArray[i].getName() << " has an appointment at " << custArray[i].getMechAppt().hours << ":" << custArray[i].getMechAppt().mins << " with " << mechArray[0].getName() << endl;
        }
        else if (custArray[i].getMechID()=="2"){
            cout << custArray[i].getName() << " has an appointment at " << custArray[i].getMechAppt().hours << ":" << custArray[i].getMechAppt().mins << " with " << mechArray[1].getName() << endl;
     
        }
        else if (custArray[i].getMechID()=="3"){
            cout << custArray[i].getName() << " has an appointment at " << custArray[i].getMechAppt().hours << ":" << custArray[i].getMechAppt().mins << " with " << mechArray[2].getName() << endl;
        }
    }
}

