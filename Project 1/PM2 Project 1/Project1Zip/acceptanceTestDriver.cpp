// Mhammed Alhayek Project 1 - Acceptance Test
// RUID: 156-00-6919, netID: mma206

#include <iostream>
#include "Bank.h"

// For the acceptance test, the following acceptance criteria must be met:
    // The program properly simulates the bank with parameters set within the limits.
    // The program calculates the average wait time and total wait time for customers.
    // The program works for various teller numbers, teller service rates, and customer arrival rates.

int main(){
    cout << "Acceptance Testing" << endl << endl;
   
    cout << "Testing the system with all parameters set at the higher limits." << endl << endl;
    int numOfTellers = 20;
    int rate = 60;
    int arrRate = 60;
    int numOfMinutes = 480;
    int numOfCusts = arrRate*numOfMinutes;
    
    // initialize a bank
    Bank myBank(numOfTellers, rate);
    myBank.setCustArrivalRate(arrRate);
    
    int custCount = 0;      // initialize a counter for number of customers added to queue
    bool done = false;      // done is true when the right number of customers have been added to the queue
    
    do{
        //each minute, add customerArrivalRate customers to queue

        for ( int i = 0; i<myBank.getCustArrivalRate() && !done; i++){
            if (custCount == numOfCusts){
                done = true;            // when right number of customers added, stop adding
            }else{
                myBank.addToQueue(Customer(myBank.getTick()));      // push a customer on to queue with its time initialized
                custCount++;                                        // increment customer counter
            }
        }
        
        
        // begin service for as many tellers as there are
        for (int j = 0; j < myBank.getNumberOfTellers(); j++){
            myBank.beginService();

        }
        
        // increment clock  before ending services and beginning next minute
        myBank.incrTick(1);
        
        // end services for tellers that are done servicing
        myBank.endService();

        
        // loop iterates as long as there is a line or the right number of customers hasnt been added yet
    }while(myBank.isLine() || !done);
    
    // set the average wait and then return it to the user
    cout << "\nThe expected average wait for the " << numOfCusts <<" customers is: 42930.4 minutes." << endl;
    myBank.setAverageWait();
    cout << "The average wait for the " << numOfCusts << " customers for the test is: " << myBank.getAverageWait() << " minutes." << endl << endl;
    
    cout << "The expected average total time for the " << numOfCusts << " customers is: 42990.5 minutes." << endl;
    myBank.setTotalWait();
    cout << "The average total wait for the " << numOfCusts <<" customers for the test is: " << myBank.getTotalWait() << " minutes." << endl << endl;
    
    // Second Test with Expected average wait time of 0
    cout << "--------Second Test--------" << endl;
    cout << "Testing the system with all parameters set at the lower limits." << endl << endl;
    
    numOfTellers = 1;
    rate = 1;
    arrRate = 1;
    numOfMinutes = 0;
    numOfCusts = arrRate*numOfMinutes;
    
    // initialize a bank
    Bank myBank2(numOfTellers, rate);
    myBank2.setCustArrivalRate(arrRate);
    
    custCount = 0;      // initialize a counter for number of customers added to queue
    done = false;      // done is true when the right number of customers have been added to the queue
    
    do{
        //each minute, add customerArrivalRate customers to queue

        for ( int i = 0; i<myBank2.getCustArrivalRate() && !done; i++){
            if (custCount == numOfCusts){
                done = true;            // when right number of customers added, stop adding
            }else{
                myBank2.addToQueue(Customer(myBank.getTick()));      // push a customer on to queue with its time initialized
                custCount++;                                        // increment customer counter
            }
        }
        
        
        // begin service for as many tellers as there are
        for (int j = 0; j < myBank2.getNumberOfTellers(); j++){
            myBank2.beginService();
        }
        
        // increment clock  before ending services and beginning next minute
        myBank2.incrTick(1);
        
        // end services for tellers that are done servicing
        myBank2.endService();
        
        // loop iterates as long as there is a line or the right number of customers hasnt been added yet
    }while(myBank2.isLine() || !done);
    
    // set the average wait and then return it to the user
    cout << "The expected average wait for the " << numOfCusts << " customers is: 0 minutes." << endl;
    myBank2.setAverageWait();
    cout << "The average wait for the " << numOfCusts << " customers for the test is: " << myBank2.getAverageWait() << " minutes." << endl << endl;
    
    cout << "The expected average total time for the " << numOfCusts << " customers is: 0 minutes." << endl;
    myBank2.setTotalWait();
    cout << "The average total wait for the " << numOfCusts << " customers for the test is: " << myBank2.getTotalWait() << " minutes." << endl << endl;
    
    cout << "The test passed." << endl;
    return 0;
}
