Problem statement
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
#include <iostream>
#include <queue>
using namespace std;
// using BFS Approach
// This Can be Done using DFS Approach as well
void BFS(int **edges, int n, int sv, bool *visited){
    queue<int> pendingVertices; // push the visited not explored yet
    
    pendingVertices.push(sv); // push the current vertex
    visited[sv] = true; // mark the currebt vertes as visited
    
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front(); // top vertex
        pendingVertices.pop();
        // now push the neighbours of current vectex in the queue
        for(int i=0; i<n; i++){
            // avoid current
            if(i == currentVertex) continue;
            // push the neighbour if not visited yet
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
bool is_connected(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    //BFS
    BFS(edges, n, 0, visited);
    // checking if visisted array has any vertes which is still unvisited after the traversal
    for(int i=0; i<n; i++){
        if(!visited[i]) return false;
    }

    //delete
    delete [] visited;
    return true;
}
int main() {
    int n, e;
    int svertex, evertex;
     
    cin>>n>>e;
    
    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }
    
    // marking edges in 2-d matrix
    int s,f;
    for(int i=0; i<e; i++){
        cin>>s>>f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    
    
    if(is_connected(edges, n)){
        cout<<"true";
    } else {
        cout<<"false";
    }
        
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}

