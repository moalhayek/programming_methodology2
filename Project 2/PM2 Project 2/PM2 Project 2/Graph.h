//  Graph.h
//  PM2 Project 2 Graph Class


#ifndef Graph_h
#define Graph_h

#include <vector>
#include <iostream>
using namespace std;

// struct for each weighted directed edge which points from src to dest
struct Edge{
    int src;
    int dest;
    int weight;
};

class Graph{
private:
    vector< vector<int> > adjMat;       // using an adjacancy matrix
    vector< Edge > edges;               // vector that keeps track of all the edges for bellman ford's algorithm
    int vertices;                       // number of vertices in the graph
    int numOfEdges;                     // number of edges in the graph
    int inf = INT_MAX/2;                // the number infinity to be used throughout the algorithms is set to INT_MAX/2
public:
    Graph();                            // default constructor sets number of vertices and number of edges to 0
    Graph(int v);                       // constructor that creates a random graph with v vertices
    void setEdge(int s, int d, int w);  // function to set the edge added to the graph and push it to edges vector
    void setNumOfVertices(int v);       // sets the number of vertices
    int getNumOfVertices();             // returns the number of vertices in the graph
    void setNumOfEdges();               // sets the number of edges in the graph
    int getNumOfEdges();                // returns the number of edges in the graph
    int dijkstraAnySrc(int weight[], int src, int dest, int hop[]); //executes dijkstra's algorithm to find the shortest path from src to dest
    int BellmanFord(int weight[], int src, int dest, int hop[]); //executes bellman ford's algorithm to find the shortest path from src to dest

    
};

#endif /* Graph_h */
