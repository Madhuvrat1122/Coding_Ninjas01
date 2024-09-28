#include <iostream>
#include <queue>
using namespace std;
// DFS
void printDFS(int n, int **edges, int startVetice, bool *visited){
    cout<<startVetice<<" ";
    visited[startVetice] = true;
    
    for(int i=0; i<n; i++){
        if(i == startVetice){
            continue;
        }
        if(edges[startVetice][i] == 1){
            if(visited[i]) continue;
            printDFS(n, edges, i, visited);
        }
    }
}
void DFS(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printDFS(n, edges, i, visited);
        }
    }
    
    // delete 
    delete [] visited;
}
// BFS
void printBFS(int n, int **edges, int sv, bool *visited){
    queue<int> pendingVertices; // push the visited not explored yet
    
    pendingVertices.push(sv); // push the current vertex
    visited[sv] = true; // mark the currebt vertes as visited
    
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front(); // top vertex
        pendingVertices.pop();
        cout<<currentVertex<<" "; // print the current vertex
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
void BFS(int **edges, int n) {
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            printBFS(n, edges, i, visited);
        }
    }
    
    // delete 
    delete [] visited;
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
    
    //BFS
    cout<<"BFS:-"<<endl;
    BFS(edges, n);
    
    //DFS
    cout<<endl;
    cout<<"DFS:-"<<endl;
    DFS(edges, n);
        
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}

// Input:-
// 9
// 7
// 0 1
// 1 3
// 3 2
// 2 0
// 2 4
// 5 6
// 7 8
// Output:-
// BFS:-
// 0 1 2 3 4 5 6 7 8 
// DFS:-
// 0 1 3 2 4 5 6 7 8
