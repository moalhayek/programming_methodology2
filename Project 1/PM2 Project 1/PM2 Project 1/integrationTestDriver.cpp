// Mhammed Alhayek Project 1 - Integration Tests
// RUID: 156-00-6919, netID: mma206

#include <iostream>
#include "Bank.h"

int main(){
    
    // Integration Testing:
    // Interactions that are supposed to work:
    
        // Bank must be able to have a line of customers
        // Bank must be able to have a certain number of tellers
        // Bank must be able to access information about times Tellers and Customers do things
            // Example
            // Customers and Tellers must be able to set times based off the Bank's clock
            // Bank must be able to distinguish whether a teller is busy or free
    
    cout << "Integration Test" << endl << endl;
    
    Bank testBank(1,1);
    Customer testCustomer1;
    Customer testCustomer2;
    Teller testTeller;
    
    cout << "Bank must be integrated with Customer so that a Bank can have a line of customers." << endl;
    cout << "Testing that a bank can have a line of customers by attempting to add customers to a bank's queue: " << endl;
    testBank.addToQueue(testCustomer1);
    testBank.addToQueue(testCustomer2);
    cout << "Two customers have been added to the line. Now checking that there is a line in the bank: " << endl;
    if (testBank.isLine()){
        cout << "testBank.isLine(): true" << endl << endl;
    }
    else{
        cout << "testBank.isLine(): false" << endl << endl;
    }
    
    cout << "Bank must be able to have a certain number of tellers." << endl;
    cout << "Testing that a bank can have tellers by adding 2 tellers to the bank and then outputting the number of tellers in the bank. Expected output: 3" << endl;
    testBank.addTeller(1);
    testBank.addTeller(1);
    cout << "testBank.getNumberOfTellers(): " << testBank.getNumberOfTellers() << endl << endl;
    
    cout << "Bank must be able to access information about times Tellers and Customers do things." << endl;
    cout << "Bank can do this by using the set and get functions of specific times such as arrival time and queue end time for customers and service start time for Tellers." << endl;
    cout << "The Bank has access to the set and get functions of the Tellers in its vector/queue of tellers and the customers in its queue of customers." << endl;
    cout << "The set and get functions were tested in the unit testing driver." << endl;
    cout << "The beginService function accesses teller and customer information and sets information for the customer. Testing this function to prove this integration test passed." << endl;
    
    if (testBank.beginService()){
        cout << "Test Passed" << endl << endl;
    }
    else{
        cout << "Test Failed" << endl << endl;
    }
    
    
    return 0;
}
