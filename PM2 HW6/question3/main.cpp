// Mhammed Alhayek Homework 6: Question 3 - Shortest-Path Algorithm

// reference: book
// reference: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <iostream>
#include <vector>

using namespace std;
int inf = INT_MAX/2; // arbitrary choice for infinity.
//class Graph{
//public:
//    Graph(int arr[][]);
//private:
//    int m;
//    vector< vector<int> > adjMat[][];
//};

void shortestPath(vector<vector<int> > graph, int weight[]);
void shortestPathAnySrc(vector<vector<int> > graph, int weight[], int src);
void displayMat(vector<vector<int> > matrix);
int main(){
    
    // the below matrix is the adjacency matrix for figure 20-39
    vector<vector<int> > arr {{inf, 2, 4, 6, inf, inf, inf},
                             {inf, inf,5, inf, 3, inf, inf},
                             {inf, inf, inf, 2, 2, inf, inf},
                             {inf, inf, 1, inf, 5, 3, inf},
                             {inf, inf, 3, inf, inf, 5, 1},
                             {inf, inf, inf, inf, 1, inf, inf},
                             {inf, inf, inf, inf, inf, 2, inf}};
    
    cout << "The adjacency matrix for Figure 20-39 is: " << endl;
    displayMat(arr);

    int size = arr.size();
    int dist[size];
    int dist2[size];
    cout << "\nImplementing shortest path algorithm for figure 20-39 with 0 as the origin." << endl;
    
    shortestPath(arr, dist);
    shortestPathAnySrc(arr, dist2, 4);
    
    cout << "The resulting weight array is: " << endl;
    for (int i = 0; i<size; i++){
        if (dist[i] == inf){
            cout << "inf" << " ";
        }
        else
            cout << dist[i] << " ";
    }
    cout << endl;

    cout << "\nImplementing shortest path algorithm for figure 20-39 with 4 as the origin." << endl;
    
    cout << "The resulting weight array is: " << endl;
    for (int i = 0; i<size; i++){
        if (dist2[i] == inf){
            cout << "inf" << " ";
        }
        else
            cout << dist2[i] << " ";
    }
    cout << endl;
    return 0;
}


// Finds the minimum-cost paths between an origin vertex
// (vertex 0) and all other vertices in a weighted directed
// graph theGraph; theGraph’s weights are nonnegative
void shortestPath(vector<vector<int> > graph, int weight[]){
    // Step 1: initialization
    int n = graph.size();       // number of vertices in the graph
    bool vertexSet[n];          // vertexSet[i] will be true if vertex i is included in the
                                // vertexSet.
    for (int v = 1; v<n; v++){
        // initializing weights to direct distance from source to dest
        weight[v] = graph[0][v];
    }
    
    // Initialize all vertices in vertexSet[] as false
    for (int i = 0; i < n; i++){
        vertexSet[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    weight[0] = 0;
    
    // ----- End of Step 1 -----

    
    // Steps 2 through n
    // Invariant: For v not in vertexSet, weight[v] is the
    // smallest weight of all paths from 0 to v that pass
    // through only vertices in vertexSet before reaching
    // v. For v in vertexSet, weight[v] is the smallest
    // weight of all paths from 0 to v (including paths
    // outside vertexSet), and the shortest path
    // from 0 to v lies entirely in vertexSet.
    
    for (int step = 2; step <= n; step++){
        //Find the smallest weight[v] such that v is not in vertexSet
        int min = inf;        // current smallest weight[v], initially inf
        int smallest;         // index of smallest weight
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
                if(weight[u] > weight[smallest] + graph[smallest][u]){
                    weight[u] = weight[smallest] + graph[smallest][u];
                }
            }
        }
    }
    
    
}

//---------- Modifying the algorithm so that any vertex can be the origin ----------//


// Finds the minimum-cost paths between an origin vertex
// (vertex 0) and all other vertices in a weighted directed
// graph theGraph; theGraph’s weights are nonnegative
void shortestPathAnySrc(vector<vector<int> > graph, int weight[], int src){
    // Step 1: initialization
    int n = graph.size();       // number of vertices in the graph
    bool vertexSet[n];          // vertexSet[i] will be true if vertex i is included in the
    // vertexSet.
    for (int v = 0; v<n; v++){
        // initializing weights to direct distance from source to dest
        weight[v] = graph[src][v];
    }
    
    // Initialize all vertices in vertexSet[] as false
    for (int i = 0; i < n; i++){
        vertexSet[i] = false;
    }
    
    // Distance of source vertex from itself is always 0
    weight[src] = 0;
    
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
                if(weight[u] > weight[smallest] + graph[smallest][u]){
                    weight[u] = weight[smallest] + graph[smallest][u];
                }
            }
        }
    }
    
    
}

void displayMat(vector<vector<int> > matrix){
    for (int i = 0; i<matrix.size(); i++){
        for (int j = 0; j<matrix.size();j++){
            if (matrix[i][j] == inf){
                cout << "inf" << " ";
            }
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
