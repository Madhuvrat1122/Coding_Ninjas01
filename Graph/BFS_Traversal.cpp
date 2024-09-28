#include <iostream>
#include <queue>
using namespace std;
// BFS
void print(int n, int **edges, int sv){
    queue<int> pendingVertices; // push the visited not explored yet
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    pendingVertices.push(sv); // push the current vertex
    visited[sv] = true; // mark the currebt vertes as visited
    
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front(); // top vertex
        visited[currentVertex] = true;
        pendingVertices.pop();
        cout<<currentVertex<<" "; // print the current vertex
        // now push the neighbours of current vectex in the queue
        for(int i=0; i<n; i++){
            // avoid current
            if(i == currentVertex) continue;
            // push the neighbour if not visited yet
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
            }
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
    
    int s,f;
    for(int i=0; i<e; i++){
        cin>>s>>f;
        edges[s][f] = 1;
    }
    
    //BFS
    print(n, edges, 0);
    
    //delete
    for(int i=0; i<n; i++){
        delete[] edges[i];
    }

    return 0;
}
