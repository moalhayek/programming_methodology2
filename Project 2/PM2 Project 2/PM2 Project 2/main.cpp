// Mhammed Alhayek Project 2 Type 1B
// reference: book
// reference: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
// reference: http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
// reference: http://www.cplusplus.com/forum/beginner/40563/
// last reference is for calculating time of a program


#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include "Graph.h"

using namespace std;
int inf = INT_MAX/2; // arbitrary choice for infinity.

int main(){
    //srand(time(0));     // random seed based on current time for rand() function
    srand(6919);          // random seed based on my RUID

    
    // for loop goes from 6-13 to generate graphs of size 2^6 to 2^13
    for (int i = 6; i<= 13; i++){
        int size = pow(2,i);
        
        int dist[size];         // create array that will hold weights from source to i in dist[i]
        int dist2[size];
        int dest = size-1;      // using the last vertex, vertex size-1, as the destination
    
        // initializing sums to 0 for calculating averages
        int distSum = 0;
        int distSum2 = 0;
        int hopsSum = 0;
        int hopsSum2 = 0;
        double timeSum = 0;
        double timeSum2 = 0;
        
        // generating the 100 graphs for each size
        for (int i = 0; i < 100; i++){
            // initiate hops arrays to calculate number of hops from source to i in hops[i]
            int hops[size];
            int hops2[size];
            Graph myGraph(size);
            
            // executing dijkstra's algorithm on the graph
            int start_s=clock();        // start time of shortest path algorithm
            distSum += myGraph.dijkstraAnySrc(dist, 0,dest, hops);
            int stop_s=clock();         // stop time of shortest path algorithm
            timeSum += (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000;        // adding time for algorithm to compute in ms
            hopsSum += hops[dest];
            
            // executing Bellman Ford's algorithm on the graph
            int start_s2=clock();        // start time of shortest path algorithm
            distSum2 += myGraph.BellmanFord(dist2, 0,dest,hops2);
            int stop_s2=clock();         // stop time of shortest path algorithm
            timeSum2 += (stop_s2-start_s2)/double(CLOCKS_PER_SEC)*1000;        // adding time for algorithm to compute in ms
            hopsSum2 += hops2[dest];
        }
    
        // averages are total sums divided by number of graphs
        float aveSum = distSum/100.0;
        float aveHops = hopsSum/100.0;
        double aveTime = timeSum/100.0;
        float aveHops2 = hopsSum2/100.0;
        float aveSum2 = distSum2/100.0;
        double aveTime2 = timeSum2/100.0;
        
        
        cout << "Using dijkstra's Algorithm: " << endl;
        cout << "Size\t\t\t" << "Average Weight\t\t\t" << "Hops\t\t\t" << "Average Time" << endl;
        cout << size << "\t\t\t" << aveSum << "\t\t\t\t" << aveHops << "\t\t\t" << aveTime << endl;
        
        cout << "Using Bellman Ford's Algorithm: " << endl;
        cout << "Size\t\t\t" << "Average Weight\t\t\t" << "Hops\t\t\t" << "Average Time" << endl;
        cout << size << "\t\t\t" << aveSum2 << "\t\t\t\t" << aveHops2 << "\t\t\t" << aveTime2 << endl;
    }


    return 0;
}


