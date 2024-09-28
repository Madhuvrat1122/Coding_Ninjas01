// Problem statement
// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

// Note:

// 1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
// 2. E is the number of edges present in graph G.
// 3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V - 1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Sample Input 1:
// 4 2
// 0 1
// 2 3
// Sample Output 1:
// 0 1 
// 2 3 
// Sample Input 2:
// 4 3
// 0 1
// 1 3 
// 0 3
// Sample Output 2:
// 0 1 3 
// 2
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// Can Be Done Using DFS as well But Using BFS Here.
void getPath_BFS(int n, int **edges, int sv, bool *visited, vector<int> &path){
    queue<int> pendingVertices; // push the visited not explored yet
    
    pendingVertices.push(sv); // push the current vertex
    visited[sv] = true; // mark the currebt vertes as visited
    
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front(); // top vertex
        pendingVertices.pop();
        path.push_back(currentVertex); // print the current vertex
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
vector<vector<int>> all_connnected_component_func(int** edges, int n){
    bool *visited = new bool[n];
    vector<vector<int>> allPaths;
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> path;
            getPath_BFS(n, edges, i, visited, path);
            if (path.size() > 0) {
                sort(path.begin(), path.end());
                allPaths.push_back(path);
            }
        }
    }
    
    // delete
    delete [] visited;
    return allPaths;
}
int main()
{
    int n, e;
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
    
    //Using BFS
    vector<vector<int>> all_connnected_component = all_connnected_component_func(edges, n);
    for(int i=0; i<all_connnected_component.size(); i++){
        for(int j=0; j<all_connnected_component[i].size(); j++){
            cout<<all_connnected_component[i][j]<<" ";
        }
        cout<<endl;
    }
    
        
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}

