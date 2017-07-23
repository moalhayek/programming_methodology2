// Mhammed Alhayek Project 1
// RUID: 156-00-6919, netID: mma206

#include <iostream>
#include "Bank.h"


int main(int argc, const char * argv[]) {
    
    // get number of tellers from user
    cout << "Enter the number of tellers: ";
    int numOfTellers;
    cin >> numOfTellers;
    
    // make sure input is valid
    while(cin.fail() || numOfTellers <= 0 || numOfTellers >20){
        cout << "Must enter a positive integer less than or equal to 20, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> numOfTellers;
    }
    
    // get teller service rate from user
    cout << "Enter the teller service rate (minutes/customer): ";
    int rate;
    cin >> rate;
    
    // make sure input is valid
    while(cin.fail() || rate <= 0 || rate > 60){
        cout << "Must enter a positive integer less than or equal to 60, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> rate;
    }
    
    
    // get customer arrival rate from user
    cout << "Enter the customer arrival rate (customers/minute): ";
    int arrRate;
    cin >> arrRate;
    
    // make sure input is valid
    while(cin.fail() || arrRate <= 0 || arrRate > 60){
        cout << "Must enter a positive integer less than or equal to 60, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> arrRate;
    }
    
    // get number of customers to check average wait for from user
    cout << "Enter how many minutes the customers come in for: ";
    int numOfMinutes;
    cin >> numOfMinutes;
    
    // make sure input is valid
    while(cin.fail() || numOfMinutes < 0 || numOfMinutes > 480){
        cout << "Must enter a non-negative integer less than or equal to 480, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> numOfMinutes;
    }
    
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
            if (myBank.beginService()){
                //cout << "Customer taken from queue at minute: " << myBank.getTick() << endl;
            }
            //else
                //cout << "No customers in queue or all tellers busy at minute: " << myBank.getTick() << endl;
        }
        
        // increment clock  before ending services and beginning next minute
        myBank.incrTick(1);
        
        // end services for tellers that are done servicing
        myBank.endService();
        
        // loop iterates as long as there is a line or the right number of customers hasnt been added yet
    }while(myBank.isLine() || !done);
    
    // set the average wait and then return it to the user
    myBank.setAverageWait();
    cout << "The average wait is: " << myBank.getAverageWait() << " minutes" << endl;
    return 0;
}
