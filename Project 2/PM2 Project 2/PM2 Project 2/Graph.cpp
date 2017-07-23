//  Graph.cpp
//  PM2 Project 2 Graph Class Implementation File

#include "Graph.h"

using namespace std;

// constructor that creates a random graph with v vertices
// fully connected graph with random weights
Graph::Graph(int v) : vertices(v){
    // create v vectors of ints and push them on to a vector
    for (int i = 0; i<v; i++){
        vector< int > row;
        int weight;
        for (int j = 0; j<v; j++){
            if (i == j){
                // diagonals of the matrix should be infinity
                weight = inf;
                row.push_back(weight);
            }
            else{
                // create random weights for the other edges
                weight = rand()%500 + 1;          // random number from 1-500
                row.push_back(weight);          // assign that weight to new edge
                setEdge(i, j, weight);         // add that edge to edges array
            }
        }
        adjMat.push_back(row);
    }
    
    setNumOfEdges();
}

// default constructor sets number of vertices and number of edges to 0
Graph::Graph() : vertices(0), numOfEdges(0){
}

void Graph::setEdge(int s, int d, int w){
    //set edges values and then push them on to the vector of edges
    Edge e;
    e.dest = d;
    e.src = s;
    e.weight = w;
    
    edges.push_back(e);
}

void Graph::setNumOfVertices(int v){
    // set number of vertices to v
    vertices = v;
}

int Graph::getNumOfVertices(){
    // return number of vertices
    return vertices;
}

void Graph::setNumOfEdges(){
    // set number of edges to the number of edges there are in the graph/edges vector
    numOfEdges = edges.size();
}
int Graph::getNumOfEdges(){
    // return the number of edges
    return numOfEdges;
}

int Graph::dijkstraAnySrc(int weight[], int src, int dest, int hop[]){
    // Step 1: initialization
    int n = vertices;       // number of vertices in the graph
    bool vertexSet[n];          // vertexSet[i] will be true if vertex i is included in the
    // vertexSet.
    for (int v = 0; v<n; v++){
        // initializing weights to direct distance from source to dest
        weight[v] = adjMat[src][v];
        // Initialize all vertices in vertexSet[] as false
        vertexSet[v] = false;
        hop[v] = 1;
    }
    /*
    // Initialize all vertices in vertexSet[] as false
    for (int i = 0; i < n; i++){
        vertexSet[i] = false;
    }
     */
    
    // Distance of source vertex from itself is always 0
    weight[src] = 0;
    hop[src] = 0;
    
    // ----- End of Step 1 -----
    
    
    // Steps 2 through n
    // Invariant: For v not in vertexSet, weight[v] is the
    // smallest weight of all paths from src to v that pass
    // through only vertices in vertexSet before reaching
    // v. For v in vertexSet, weight[v] is the smallest
    // weight of all paths from 0 to v (including paths
    // outside vertexSet), and the shortest path
    // from 0 to v lies entirely in vertexSet.
    
    for (int step = 2; step <= n; step++){
        //Find the smallest weight[v] such that v is not in vertexSet
        int min = inf;        // current smallest weight[v], initially inf
        int smallest;         // index of smallest weight initially 0
        for (int v = 0; v<n; v++){
            if (!vertexSet[v] && weight[v] <= min){
                // if v is not in the vertex set and weight from source to v is less than min,
                // it is new min
                min = weight[v];
                smallest = v;  // index of smallest weight
            }
        }
        
        //Add v to vertexSet
        vertexSet[smallest] = true;
        
        // Check weight[u] for all u not in vertexSet
        for (int u = 0; u<n; u++){
            if (!vertexSet[u]){
                // if there is a path from source to smallest to u that is less than from source to u, update the weight
                if(weight[u] > weight[smallest] + adjMat[smallest][u]){
                    weight[u] = weight[smallest] + adjMat[smallest][u];
                    // number of hops is going to be number of hops from source to smallest, plus 1 hop from smallest to u
                    hop[u] = hop[smallest] + 1;
                }
            }
        }
    }
    
    // return the weight to go from source to dest
    return weight[dest];
}

int Graph::BellmanFord(int weight[], int src, int dest, int hop[]){
    int V = vertices;       // initializing V to number of vertices
    int E = numOfEdges;    // initializing E to number of Edges
    
    // Step 1: Initilialize distances from src to all other vertices as infinite
    for (int i = 0; i < V; i++){
        weight[i] = inf;
        hop[i] = 1;
    }
    weight[src] = 0;        // initialize distance from source to itself as 0
    hop[src] = 0;
    
    
    // Step 2: calculate shortest distances. Do this V - 1 times.
    for (int i = 0; i<V-1; i++){
        // iterate through all edges
        for (int j = 0; j<E; j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            // if there is a path from source to j to v that is less than from source to v, update the weight of v
            if (weight[u] != inf && ((weight[u] + w) < weight[v])){
                weight[v] = weight[u] + w;
                // number of hops is going to be number of hops from source to u, plus 1 hop from u to v
                hop[v] = hop[u] + 1;
            }
        }
    }
    
    
    // note, step 3 is not needed for the project because all weights are positive
    // Step 3: check for negative-weight cycles; If a shorter path than before exists, there is a negative-weight cycle
    
    for (int i = 0; i<E; i++){
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (weight[u] != inf && ((weight[u] + w) < weight[v])){
            cout << "Graph containts a negative weight cycle" << endl;
        }
    }
    
    // return the weight to go from source to dest
    return weight[dest];
}
