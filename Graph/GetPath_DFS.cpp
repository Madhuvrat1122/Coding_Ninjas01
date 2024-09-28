// Problem statement
// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

// Find the path using DFS and print the first path that you encountered.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
// 4. Save the input graph in Adjacency Matrix.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V <= 1000
// 1 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// 0 <= v1 <= 2^31 - 1
// 0 <= v2 <= 2^31 - 1
// Time Limit: 1 second
// Sample Input 1:
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1:
// 3 0 1
// Sample Input 2:
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2:

#include <iostream>
#include <vector>
using namespace std;
// Using DFS Approach
vector<int> getPath_DFS(int **edges, int n, bool *visited, int sv, int ev){
    // Base case
    if(sv == ev){
        vector<int> path;
        path.push_back(ev);
        return path;
    }
    
    visited[sv] = true;
    
    for(int i=0; i<n; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]) continue;
            vector<int> path = getPath_DFS(edges, n, visited, i, ev);
            if(path.size() > 0){ // if there is a path exist
                path.push_back(sv);
                return path;
            }
        }
    }
    
    vector<int> noPath;
    return noPath; // if there is no path exist
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
    
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    //BFS
    vector<int> path = getPath_DFS(edges, n, visited, svertex, evertex);
    if(path.size() > 0){
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
    }
        
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}
