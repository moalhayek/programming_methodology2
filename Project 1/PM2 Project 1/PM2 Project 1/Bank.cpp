// PM2 Project 1
// Bank.cpp
// Implementation file for Bank class


#include "Bank.h"

using namespace std;

// constructor always initializes tick to 0, numberOfTellers to 1, teller rate to 1
Bank::Bank() : tick(0), numberOfTellers(1){
    freeTeller.push(Teller(1));
}

Bank::~Bank(){}                 // destructor

// constructor that takes the tellers rate and the number of tellers and initializes them
Bank::Bank(int numTell, int tellRate) : tick(0), numberOfTellers(numTell){
    // push the number of tellers initialized on to the free tellers queue
    for (int i = 0; i < numTell; i++){
        freeTeller.push(Teller(tellRate));
    }
}


int Bank::getCustArrivalRate(){
    return custArrivalRate;
}

void Bank::setCustArrivalRate(int rate){
    custArrivalRate = rate;
}

void Bank::addToQueue(Customer cust){
    // push a customer on to the queue with its arrival time set to the current time
    cust.setArrival(tick);
    line.push(cust);
    
}

int Bank::getNumberOfTellers(){
    return numberOfTellers;
}

void Bank::addTeller(int rate){
    if (numberOfTellers<20){
        numberOfTellers++;
        freeTeller.push(Teller(rate));
    }
    else{
        cout << "Teller limit reached, teller not added." << endl;
    }
}

bool Bank::beginService(){
    // if no free tellers available, return false
    if(freeTeller.empty()){
        return false;
    }
    else{
        // if no line of customers, return false, else, begin service
        if (isLine()){
            // take the next customer off the front of the line and remove him from the line
            Customer nextCust = line.front();
            line.pop();
            // set the time the customer came off the queue
            nextCust.setQueueEnd(tick);
            // set the customers wait time
            nextCust.setWait();
            // add the wait time to the vector of data
            waitData.push_back(nextCust.getWait());
            // set the customer total time
            nextCust.setTotal(freeTeller.front().getRate());
            // push the total time on to the vector of data
            totalWait.push_back(nextCust.getTotal());
            
            // set the time the teller started servicing and then move him from the free teller queue to the busy teller vector
            freeTeller.front().setServiceStartTime(tick);
            busyTeller.push_back(freeTeller.front());
            freeTeller.pop();
            return true;
        }
        else{
            return false;
        }
    }
}

void Bank::endService(){
    // for every teller in the busy teller vector, check if they are done servicing
    for ( int i = 0; i < busyTeller.size(); i++){
        // if the teller is done servicing, move the teller to the free teller queue
        // vector is used so that if tellers have different service times, they can be taken out of vector in any order
        if ((tick - busyTeller[i].getServiceStartTime()) == (busyTeller[i].getRate())){
            freeTeller.push(busyTeller[i]);
            busyTeller.erase(busyTeller.begin() + i);
            i--;            // decrement counter because tellers after the one removed are shifted left
        }
    }
}

int Bank::getTick(){
    return tick;
}

void Bank::incrTick(int incrAmount){
    tick+= incrAmount;
}

float Bank::getAverageWait(){
    return averageWait;
}

void Bank::setAverageWait(){
    if (waitData.size() == 0){
        averageWait = 0;
    }
    else{
        float sum = 0;
        // add all the wait times to the sum
        for ( int i = 0; i < waitData.size(); i++){
            sum += waitData[i];
        }
    
        // average wait is sum divided by number of wait times
        averageWait = sum/waitData.size();
    }
}

bool Bank::isLine(){
    return !line.empty();
}

float Bank::getTotalWait(){
    return averageTotal;
}

void Bank::setTotalWait(){
    if (totalWait.size() == 0){
        averageTotal = 0;
    }
    else{
        float sum = 0;
        // add all the wait times to the sum
        for ( int i = 0; i < totalWait.size(); i++){
            sum += totalWait[i];
        }
        
        // average wait is sum divided by number of wait times
        averageTotal = sum/totalWait.size();
    }
}
