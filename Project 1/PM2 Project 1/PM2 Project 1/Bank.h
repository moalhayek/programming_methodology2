// PM2 Project 1
// Bank.h
// Header file for Bank class

#ifndef Bank_h
#define Bank_h

#include <queue>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "Teller.h"


using namespace std;

class Bank{
public:
    // default constructor always initializes tick to 0, numberOfTellers to 1, teller rate to 1
    Bank();
    ~Bank();
    
    // constructor that takes the tellers rate and the number of tellers and initializes them
    Bank(int tellNum, int tellRate);
    
    /** gets the customer arrival rate value
     @pre custArrivalRate is set
     @post custArrivalRate is returned
     */
    int getCustArrivalRate();
    
    /** sets the customer arrival rate value
     @pre rate is a positive integer referring to the rate at which customers arrive to the bank
     @post custArrivalRate is set equal to rate
     @param rate rate of customers that arrive at the bank in customers/min; 1 <= rate <= 60
     */
    void setCustArrivalRate(int rate);
    
    /** adds a customer to the queue
     @pre Customers are initialized with the time they enter the queue
     @post that customer is added to the queue
     @param cust customer to be added to the queue
     */
    void addToQueue(Customer cust);
    
    /** gets the number of tellers in the bank
     @pre numberOfTellers is set
     @post numberOfTellers is returned
     */
    int getNumberOfTellers();
    
    /** adds a teller to the bank
     @pre rate is a positive integer referring to the service rate for the teller you want to add; numberOfTellers is less than 20
     @post numberOfTellers is incremented by 1, a free teller is added with the service rate give
     @param rate service rate for the teller added to the bank; 1 <= rate <= 60
     */
    void addTeller(int rate);
    
    /** gets the average wait of customers
     @pre averageWait is set
     @post averageWait is returned
     */
    float getAverageWait();
    
    /** sets the average wait of customers
     @pre the vector waitData contains the amount of time each customer waited
     @post the average wait of all these customers is calculated and the value of averageWait is set to that
     */
    void setAverageWait();
    
    /** takes a customer from the queue and assigns him/her to a teller, also calculates customers wait time
     @pre none
     @post next customer in queue (if any) is serviced as long as there is a free teller
     @return returns true if a customer was serviced, false otherwise
     */
    bool beginService();
    
    /** Checks if any teller is done servicing a customer
     @pre none
     @post tellers done servicing are made available for the next customer
     */
    void endService();
    
    /** gets the current time in the system
     @pre none
     @post tick is returned to the user
     */
    int getTick();
    
    /** increments the clock by the desired amount
     @pre incrAmount is a positive integer equal to how many units you want to increment the clock by
     @post tick is incremented by incrAmount
     */
    void incrTick(int incrAmount);
    
    /** lets the user know if there is a line of customers
     @pre none
     @post if there are customers in the queue, it returns true, else, returns false
     */
    bool isLine();
    
    /** gets the average total time spent in bank by customers
     @pre averageTotal is set
     @post averageTotal is returned
     */
    float getTotalWait();

    /** sets the average total wait of customers
     @pre the vector totalData contains the amount of time each customer waited
     @post the average total wait of all these customers is calculated and the value of averageTotal is set to that
     */
    void setTotalWait();
    
private:
    int custArrivalRate;            // customers/min
    int numberOfTellers;            // number of tellers in the bank
    float averageWait;              // average wait time of the customers
    float averageTotal;             // average total time spent in the bank by a customer
    int tick;                       // clock that keeps track of what time it is
    queue <Customer> line;          // line of customers
    queue <Teller> freeTeller;      // Tellers waiting for a customer
    vector <Teller> busyTeller;     // Tellers still performing a service
    vector <int> waitData;          // vector that calculates how long each customer waited
    vector <int> totalWait;         // vector that calculates how long a customer spent in the system
};

#endif /* Bank_h */
