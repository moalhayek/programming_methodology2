// Mhammed Alhayek Homework 2: Question 2 - Towers of Hanoi Iterative Solution

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>


// reference: http://www.geeksforgeeks.org/iterative-tower-of-hanoi/
using namespace std;

// class Disk created to represent an actual disk on the tower
class Disk{
public:
    Disk(int num){
        setDiskNumber(num);
    }
    void setDiskNumber(int num){
        disknumber = num;
    }
    int getDiskNumber(){
        return disknumber;
    }
    
private:
    int disknumber;
};

void moveDisk(string source, string destination);
void iterativeSolveTowers(int count, string source, string destination, string spare);
void moveBetweenPoles(stack<Disk> &src, stack<Disk> &dest, string source, string destination);



int main(int argc, const char * argv[]) {
    
    // ask the user how many disks to solve the puzzle for
    int N;
    cout << "Enter N, the number of disks: ";
    cin >> N;
    
    cout << "Iterative Solution: " << endl;
    iterativeSolveTowers(N, "A", "B", "C");
    
    return 0;
}

/** Makes the legal move between two poles. A legal move is one that prevents a bigger disk from being place on top of a smaller disk.
 @pre src and dest are the stacks of disks on the source pole and destination pole. source and destination are strings that represent the tower name
 @post A disk is moved between the src tower and the dest tower legally.
 @param src The stack that represents the tower of disks on the source tower
 @param source The string name for the source tower.
 @param destination The string name for the destination tower.
 @param dest The stack that represents the tower of disks on the destination tower
 
 */

void moveBetweenPoles(stack<Disk> &src, stack<Disk> &dest, string source, string destination){
    // if one of the towers is empty, move a disk to that tower
    if (src.empty()){
        // push the top disk from the destination tower to the source tower.
        // then pop it off the destination tower
        src.push(dest.top());
        dest.pop();
        moveDisk(destination, source);
        return;
    }
    else if (dest.empty()){
        // push the top disk from the source tower to the destination tower.
        // then pop it off the source tower
        dest.push(src.top());
        src.pop();
        moveDisk(source, destination);
        return;
    }
    
    // get the size of the top disk from each tower
    int srcTop = src.top().getDiskNumber();
    int destTop = dest.top().getDiskNumber();
    
    // move the smaller disk on top of the bigger disk
    if (srcTop > destTop){
        src.push(dest.top());
        dest.pop();
        moveDisk(destination, source);
        return;
    }
    else if (destTop > srcTop){
        dest.push(src.top());
        src.pop();
        moveDisk(source, destination);
        return;
    }
    
}



/** Solves the Towers of Hanoi Puzzle for count number of disks using iteration.
 @pre count > 0
 @post The algorithm for solving the puzzle is displayed to user.
 @param count The number of disks initially on the source tower.
 @param source The string name for the source tower.
 @param destination The string name for the destination tower.
 @param spare The string name for the spare tower
 
 */

void iterativeSolveTowers(int count, string source, string destination, string spare){
    // First calculate number of moves required, always (2^n - 1)
    int moves = pow(2,count) - 1;
    
    // 3 stacks used to mimic the 3 towers
    stack<Disk> src;
    stack<Disk> dest;
    stack<Disk> spar;
    
    for (int i = count; i >0; i--){
        // push the Disks on to the source stack from largest to smallest
        src.push(Disk(i));
    }

    // If the number of disks is even, swap the destination pole and the spare pole.
    if (count % 2 == 0){
        string temp = spare;
        spare = destination;
        destination = temp;
        
        
    }
    
    // different moves made based off which move number it is. different move every 3 moves.
    for (int i = 1; i<=moves; i++){
        if (i % 3 == 1){
            //legal movement of top disk between source pole and destination pole
            moveBetweenPoles(src, dest, source, destination);
            
        }
        else if (i % 3 == 2){
            //legal movement of top disk between source pole and spare pole
            moveBetweenPoles(src, spar, source, spare);
        }
        else if (i % 3 == 0){
            //legal movement of top disk between spare pole and destination pole
            moveBetweenPoles(spar, dest, spare, destination);
        }
    }

}

/** Displays to the user that a move was made from source to destination
 @pre source and destination are strings that represent the tower name
 @post The move made is displayed to user.
 @param source The string name for the source tower.
 @param destination The string name for the destination tower.
 */

void moveDisk(string source, string destination){
    cout << "Move top disk from pole " << source << " to pole " << destination << endl;
}



