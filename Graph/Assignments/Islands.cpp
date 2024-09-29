// Problem statement
// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= V <= 1000
// 0 <= E <= (V * (V-1)) / 2
// 0 <= a <= V - 1
// 0 <= b <= V - 1
// Time Limit: 1 second
// Sample Input 1:
// 5 8
// 0 1
// 0 4
// 1 2
// 2 0
// 2 4
// 3 0
// 3 2
// 4 3
// Sample Output 1:
// 1 
#include <iostream>
using namespace std;
void DFS(int **edges, int n, int sv, bool *visited){
    visited[sv] = true;
    for(int i=0; i<n; i++){
        if(sv == i) continue;
        if(edges[sv][i] == 1 && !visited[i]) {
            DFS(edges, n, i, visited);
        }
    }
}
int connectedIslands(int **edges, int n){
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }

    int groups = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(edges, n, i, visited);
            groups++;
        }
    }

    delete [] visited;

    return groups;
}
int main() {
    int n, e;
    cin>>n>>e;

    int **edges = new int*[n];
    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j] = 0;
        }
    }

    // take edges input
    int sv, ev;
    for(int i=0; i<e; i++){
        cin>>sv>>ev;;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }

    cout<<connectedIslands(edges, n);

    //deallocate the edges
    for(int i=0; i<n; i++){
        delete [] edges[i];
    }
}
