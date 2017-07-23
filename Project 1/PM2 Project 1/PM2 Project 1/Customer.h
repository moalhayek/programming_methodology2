// PM2 Project 1
// Customer.h
// Header file for Customer class

#ifndef Customer_h
#define Customer_h

#include <cstdlib>

class Customer{
public:
    // default constructors and destructors
    Customer();
    ~Customer();
    
    // constructor that initializes the time a customer arrived
    Customer(int arrTime);
    
    /** gets the customer arrival time value
     @pre arrivalTime is set
     @post arrivalTime is returned
     */
    int getArrival();
    
    /** sets the customer arrival time value
     @pre arrTime is >= 0
     @post arrivalTime is set equal to the time the customer arrived at a bank
     @param arrTime time a customer arrived at a bank
     */
    void setArrival(int arrTime);
    
    /** gets the time the customer stopped waiting in line
     @pre queueEndTime is set
     @post queueEndTime is returned
     */
    int getQueueEnd();
    
    /** sets the time a customer stopped waiting in line
     @pre endTime is >= 0
     @post queueEndTime is set equal to the time the customer stopped waiting in line
     @param endTime time a customer stopped waiting in line
     */
    void setQueueEnd(int endTime);
    
    /** gets the length of time the customer waited in line
     @pre waitTime is set
     @post waitTime is returned
     */
    int getWait();
    
    /** sets the time a customer stopped waiting in line
     @pre arrivalTime and queueEndTime are set
     @post waitTime is set equal to the length of time a customer waited in line
     */
    void setWait();
    
    /** gets the length of time the customer was in the bank
     @pre totalTime is set
     @post totalTime is returned
     */
    int getTotal();
    
    /** sets the length of time the customer was in the bank
     @pre waitTime is set, tellRate is the rate for the teller that serviced the customer
     @post totalTime is set
     @param tellRate the service rate for the teller that services this customer
     */
    void setTotal(int tellRate);
    
private:
    int arrivalTime;            // time the customer arrived at the bank
    int queueEndTime;           // time the customer stopped waiting in line
    int waitTime;               // length of time the customer waited in line
    int totalTime;              // lenght of time the customer was at the bank
    
};

#endif /* Customer_h */
