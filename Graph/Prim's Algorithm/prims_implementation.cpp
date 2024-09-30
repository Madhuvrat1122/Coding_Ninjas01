// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.



// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.



// For printing MST follow the steps -

// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note: Order of different edges doesn't matter.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V, E <= 10^5
// 1 <= Wi <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Input Graph



// Sample Output 1 :
// 0 1 3
// 1 2 1
// 0 3 5

#include <iostream>
#include <climits>
using namespace std;
// method for finding the minimum weight un-visited vertex
int findMinVertex(int *weight, bool *visited, int v){
    int minVertex = -1;
    for(int i=0; i<v; i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}
// implmentation of prims algorithm
void prims(int **edges, int v, int e){
    int *weight = new int[v];
    int *parent = new int[v];
    bool *visited = new bool[v];
    // initially all vertices are un-visisted and weight assigned is maximum
    for(int i=0; i<v; i++){
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    // for starting node which is 0 in our case there is no paren to it and since there is not parent weight is 0
    parent[0] = -1;
    weight[0] = 0;
    // now find the minimum weight vertex and mark is visited and then explore all its neighbours
    // reason for going till v-1 instead of v is because last vertex will automatically calculated
    for(int i=0; i<v-1; i++){
        // find min weight vertex
        int minVertex = findMinVertex(weight, visited, v);
        visited[minVertex] = true;
        // explore all its neighbours
        for(int j=0; j<v; j++){
            // find neighbour which has edge and not visited
            if(edges[minVertex][j] != 0 && !visited[j]){
                // compare its weight with the weight store in weight array
                if(edges[minVertex][j] < weight[j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    //print the MST
    for(int i=1; i<v; i++){
        if(parent[i] < i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        } else {
             cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}
int main() {
    int v, e;
    cin>>v>>e;
    //adjancy matrix
    int **edges = new int*[v];
    for(int i=0; i<v; i++){
        edges[i] = new int[v];
        for(int j=0; j<v; j++){
            edges[i][j] = 0; // currently no edges deines for any vertex
        }
    }
    // edges input
    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    cout<<endl;

    //prim's algo
    prims(edges, v, e);
}
