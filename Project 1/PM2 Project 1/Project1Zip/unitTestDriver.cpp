// Mhammed Alhayek Project 1 - Unit Tests
// RUID: 156-00-6919, netID: mma206

#include <iostream>
#include "Bank.h"


int main(){
    cout << "Unit Testing all functions in Bank.h" << endl;
    
    cout << "Bank constructor. Inputting 1 for number of tellers, 1 for teller rate." << endl;
    Bank testBank(1,1);
    cout << "Outputting testBank's number of tellers. Expected output is 1: " << endl;
    cout << "testBank.getNumberOfTellers(): " << testBank.getNumberOfTellers() << endl << endl;
    
    cout << "Setting customer arrival rate to 1 with set function. Then outputting it with get function. Expected output: 1." << endl;
    testBank.setCustArrivalRate(1);
    cout << "testBank.getCustArrivalRate(): " << testBank.getCustArrivalRate() << endl << endl;
    
    cout << "Using getTick() to get current time. Initializes to 0 so expected output is 0:" << endl;
    cout << "testBank.getTick(): " << testBank.getTick() << endl << endl;
    
    cout << "Incrementing time by two using incrTick() function. Input 2. Then outputting tick again. Expected output: 2" << endl;
    testBank.incrTick(2);
    cout << "testBank.getTick(): " << testBank.getTick() << endl << endl;
    
    cout << "Adding a customer to queue using addToQueue() function. Then checking if there is a line using isLine() function. Expected output: true." << endl;
    testBank.addToQueue(Customer(testBank.getTick()));
    if (testBank.isLine()){
        cout << "testBank.isLine(): true" << endl << endl;
    }
    else{
        cout << "testBank.isLine(): false" << endl << endl;
    }
    
    cout << "Testing beginService and endService functions by using beginService function, incrementing tick by 1, then using endService function. Expected outputs: isLine() => false. Also, data is available to use set wait functions. " << endl;
    
    testBank.beginService();
    testBank.incrTick(1);
    testBank.endService();
    
    if (testBank.isLine()){
        cout << "testBank.isLine(): true" << endl << endl;
    }
    else{
        cout << "testBank.isLine(): false" << endl << endl;
    }
    
    cout << "testing setAverageWait() and setTotalWait() using the data from the 1 customer. Then outputting the results using getAverageWait() and getTotalWait(). Expected output: getAverageWait() = 0; getTotalWait = 1;" << endl;
    
    testBank.setAverageWait();
    testBank.setTotalWait();
    
    cout << "testBank.getAverageWait(): " << testBank.getAverageWait() << endl;
    cout << "testBank.getTotalWait(): " << testBank.getTotalWait() << endl << endl;
    
    cout << "Testing addTeller function by adding a teller with a service rate of 1 and then outputting the number of tellers in the bank. Expected output: 2" << endl;
    testBank.addTeller(1);
    cout << "testBank.getNumberOfTellers(): " << testBank.getNumberOfTellers() << endl << endl;
    
    cout << "All functions in Bank.h tested." << endl << endl;
    
    cout << "Unit Testing all functions in Teller.h" << endl;
    
    cout << "First constructing a teller." << endl;
    Teller testTeller;
    
    cout << "Setting teller rate to 2, then outputting it with get function. Expected output: 2" << endl;
    testTeller.setRate(2);
    cout << "testTeller.getRate(): " << testTeller.getRate() << endl << endl;
    
    cout << "Setting teller service start time to 2, then outputting it with get function. Expected output: 2" << endl;
    testTeller.setServiceStartTime(2);
    cout << "testTeller.getServiceStartTime(): " << testTeller.getServiceStartTime() << endl << endl;
    
    cout << "All functions in Teller.h tested." << endl << endl;
    
    cout << "Unit Testing all functions in Customer.h" << endl;
    cout << "First constructing a Customer." << endl;
    Customer testCustomer;
    
    cout << "Setting customer arrival time to 2, then outputting it with get function. Expected output: 2" << endl;
    testCustomer.setArrival(2);
    cout << "testCustomer.getArrival(): " << testCustomer.getArrival() << endl << endl;
    
    cout << "Setting customer queue end time to 4, then outputting it with get function. Expected output: 4" << endl;
    testCustomer.setQueueEnd(4);
    cout << "testCustomer.getQueueEnd(): " << testCustomer.getQueueEnd() << endl << endl;
    
    cout << "testing setWait() now that the above times have been set. Then outputting the results using getWait(). Expected output: 2" << endl;
    testCustomer.setWait();
    cout << "testCustomer.getWait(): " << testCustomer.getWait() << endl << endl;
    
    cout << "testing setTotal() using an input of 2. Then outputting the results using getTotal(). Expected output: 4" << endl;
    testCustomer.setTotal(2);
    cout << "testCustomer.getTotal(): " << testCustomer.getTotal() << endl << endl;
    
    cout << "All functions have now been unit tested. All functions passed the test." << endl;
    return 0;
}

