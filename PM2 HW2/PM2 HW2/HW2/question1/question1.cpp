// Mhammed Alhayek Homework 2: Question 1 - Towers of Hanoi

#include <iostream>
#include <string>

using namespace std;



int solveTowers(int count, string source, string destination, string spare, int &movecount, int &recursiveCalls);

int main(int argc, const char * argv[]) {
    // moves is initially 0
    int moves = 0;
    int recursiveCalls = 0;
    // ask the user how many disks to solve the puzzle for
    int N;
    cout << "Enter N, the number of disks: ";
    cin >> N;
    
    
    cout << solveTowers(N, "A", "B", "C", moves, recursiveCalls) << endl;
    cout << "The number of recursive Calls is: " << recursiveCalls << endl;
    return 0;
}

/** Solves the Towers of Hanoi Puzzle for count number of disks using recursion. Returns the number of recursive calls needed to solve the puzzle.
 @pre count > 0, movecount is 0 for the first call
 @post movecount is equal to the total number of recursive calls needed to solve the puzzle. The algorithm for solving the puzzle is displayed to user.
 @param count The number of disks initially on the source tower.
 @param source The string name for the source tower.
 @param destination The string name for the destination tower.
 @param spare The string name for the spare tower
 @param movecount The counter for the number of recursive calls made.
 @return number of moves required for solving the puzzle.
 
 */
int solveTowers(int count, string source, string destination, string spare, int &movecount, int &recursiveCalls){
    //increment the numeber of calls
    recursiveCalls++;
    
    // when down to the last disk on a tower, move it from the source to the destination
    if (count == 1){
        cout << "Move a disk from " << source << " to " << destination << endl;
        // increment movecount because a move was made
        movecount++;
    }
    else{
        // move all but one disk to the spare tower
        solveTowers(count-1, source, spare, destination, movecount, recursiveCalls);
        // move the disk left to the destination
        solveTowers(1, source, destination, spare, movecount, recursiveCalls);
        // move all but one from the spare to the destination
        solveTowers(count-1, spare, destination, source, movecount, recursiveCalls);
    }
    
    return movecount;
}


