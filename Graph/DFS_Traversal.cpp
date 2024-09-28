#include <iostream>
using namespace std;
// DFS
void print(int n, int **edges, int startVetice, bool *visited){
    cout<<startVetice<<endl;
    visited[startVetice] = true;
    
    for(int i=0; i<n; i++){
        if(i == startVetice){
            continue;
        }
        if(edges[startVetice][i] == 1){
            if(visited[i]) continue;
            print(n, edges, i, visited);
        }
    }
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
    
    bool *visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    
    int s,f;
    for(int i=0; i<e; i++){
        cin>>s>>f;
        edges[s][f] = 1;
    }
    
    //DFS
    int startVetice = 0;
    print(n, edges, startVetice, visited);

    return 0;
}

// Input:-
// 7
// 7
// 0 1
// 1 5
// 5 4
// 4 3
// 3 2
// 2 6
// 2 0
// Output:-
// 0
// 1
// 5
// 4
// 3
// 2
// 6
