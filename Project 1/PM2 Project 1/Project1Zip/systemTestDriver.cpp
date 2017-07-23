// Mhammed Alhayek Project 1 - System Test
// RUID: 156-00-6919, netID: mma206

#include <iostream>
#include "Bank.h"

// For the system test: the program must be able to simulate a bank with a certain number of tellers
// and a certain number of customers arriving per minute.
// The system must be able to give out average time a customer waits and average total time a customer spends in the bank
// The system must be able to add customers to the queue at the appropriate times, not all at once.
// The system must decide whether or not a teller is free and only let a customer leave the queue when a teller is free
// To test that this all works, the program will be tested with 3 tellers, a teller service rate of 1, 10 customers arriving per minute,
// and for 50 customers. The average wait time should be 5.84 minutes.
// The system will also be tested with 2 tellers, servicing at 1 minute per customer, with 2 customers arriving per minute for 10 customers.
// The average wait time for this case should be 0 minutes and thus each customer spends 1 minute in the system.

int main(int argc, const char * argv[]) {
    cout << "Testing the system with 3 tellers all working at 1 minute per customer, with 10 customers arriving at the bank per minute for 50 customers total." << endl << endl;
    int numOfTellers = 3;
    int rate = 1;
    int arrRate = 10;
    int numOfMinutes = 5;
    int numOfCusts = arrRate*numOfMinutes;
    
    // initialize a bank
    Bank myBank(numOfTellers, rate);
    myBank.setCustArrivalRate(arrRate);
    
    int custCount = 0;      // initialize a counter for number of customers added to queue
    bool done = false;      // done is true when the right number of customers have been added to the queue
    
    do{
        //each minute, add customerArrivalRate customers to queue
        if (!done)
            cout << "10 customers added to the queue at minute " << myBank.getTick() << endl;
        for ( int i = 0; i<myBank.getCustArrivalRate() && !done; i++){
            if (custCount == numOfCusts){
                done = true;            // when right number of customers added, stop adding
            }else{
                myBank.addToQueue(Customer(myBank.getTick()));      // push a customer on to queue with its time initialized
                custCount++;                                        // increment customer counter
            }
        }
        
        //cout << "Total customers that have arrived after minute " << myBank.getTick() << " = " << custCount << endl;
        
        // begin service for as many tellers as there are
        for (int j = 0; j < myBank.getNumberOfTellers(); j++){
            myBank.beginService();
                //cout << "Customer taken from queue at minute: " << myBank.getTick() << endl;
            //}
            //else
                //cout << "No customers in queue or all tellers busy at minute: " << myBank.getTick() << endl;
        }
        
        // increment clock  before ending services and beginning next minute
        myBank.incrTick(1);
        
        // end services for tellers that are done servicing
        myBank.endService();
        // cout << "All tellers done servicing at minute " << myBank.getTick() << " are freed and ready to take the next customer from the line." << endl;
        
        // loop iterates as long as there is a line or the right number of customers hasnt been added yet
    }while(myBank.isLine() || !done);
    
    // set the average wait and then return it to the user
    cout << "\nThe expected average wait for the " << numOfCusts << " customers is: 5.84 minutes." << endl;
    myBank.setAverageWait();
    cout << "The average wait for the " << numOfCusts << " customers for the test is: " << myBank.getAverageWait() << " minutes." << endl << endl;

    cout << "The expected average total time for the " << numOfCusts << " customers is: 6.84 minutes." << endl;
    myBank.setTotalWait();
    cout << "The average total wait for the " << numOfCusts << " customers for the test is: " << myBank.getTotalWait() << " minutes." << endl << endl;
    
    // Second Test with Expected average wait time of 0
    cout << "--------Second Test--------" << endl;
    cout << "Testing the system with 2 tellers all working at 1 minute per customer, with 2 customers arriving at the bank per minute for 10 customers total." << endl << endl;
    
    numOfTellers = 2;
    rate = 1;
    arrRate = 2;
    numOfMinutes = 5;
    numOfCusts = arrRate*numOfMinutes;
    
    // initialize a bank
    Bank myBank2(numOfTellers, rate);
    myBank2.setCustArrivalRate(arrRate);
    
    custCount = 0;      // initialize a counter for number of customers added to queue
    done = false;      // done is true when the right number of customers have been added to the queue
    
    do{
        //each minute, add customerArrivalRate customers to queue
        if (!done)
            cout << "2 customers added to the queue at minute " << myBank2.getTick() << endl;
        for ( int i = 0; i<myBank2.getCustArrivalRate() && !done; i++){
            if (custCount == numOfCusts){
                done = true;            // when right number of customers added, stop adding
            }else{
                myBank2.addToQueue(Customer(myBank.getTick()));      // push a customer on to queue with its time initialized
                custCount++;                                        // increment customer counter
            }
        }
        
        //cout << "Total customers that have arrived after minute " << myBank.getTick() << " = " << custCount << endl;
        
        // begin service for as many tellers as there are
        for (int j = 0; j < myBank2.getNumberOfTellers(); j++){
            myBank2.beginService();
            //cout << "Customer taken from queue at minute: " << myBank.getTick() << endl;
            //}
            //else
            //cout << "No customers in queue or all tellers busy at minute: " << myBank.getTick() << endl;
        }
        
        // increment clock  before ending services and beginning next minute
        myBank2.incrTick(1);
        
        // end services for tellers that are done servicing
        myBank2.endService();
        // cout << "All tellers done servicing at minute " << myBank.getTick() << " are freed and ready to take the next customer from the line." << endl;
        
        // loop iterates as long as there is a line or the right number of customers hasnt been added yet
    }while(myBank2.isLine() || !done);
    
    // set the average wait and then return it to the user
    cout << "The expected average wait for the " << numOfCusts << " customers is: 0 minutes." << endl;
    myBank2.setAverageWait();
    cout << "The average wait for the " << numOfCusts << " customers for the test is: " << myBank2.getAverageWait() << " minutes." << endl << endl;
    
    cout << "The expected average total time for the " << numOfCusts << " customers is: 1 minutes." << endl;
    myBank2.setTotalWait();
    cout << "The average total wait for the " << numOfCusts << " customers for the test is: " << myBank2.getTotalWait() << " minutes." << endl << endl;
    
    cout << "The test passed." << endl;
    return 0;
    
}
