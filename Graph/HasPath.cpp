// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= 1000
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= V - 1
// 0 <= v2 <= V - 1
// Time Limit: 1 second
// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// true
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
// false

#include <iostream>
#include <queue>
using namespace std;
// Using BFS Approach
bool hasPath_BFS(int **edges, int n, int sv, int ev){
    queue<int> pendingVertices; // push the visited not explored yet
    
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
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
                if(i == ev){
                    return true;
                }
                pendingVertices.push(i);
                 visited[i] = true;
            }
        }
    }
    
     // delete 
    delete [] visited;
    
    return false; // if reached here it means there is no path
}
int main()
{
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
    
    cin>>svertex>>evertex;
    
    //BFS
    cout<<hasPath_BFS(edges, n, svertex, evertex);
    
        
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}
