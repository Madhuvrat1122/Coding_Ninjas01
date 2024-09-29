// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

// For printing MST follow the steps -

// 1. In one line, print an edge which is part of MST in the format - 
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= V, E <= 10^5
// Time Limit: 1 sec
// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8
// Input Graph

// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5
#include <bits/stdc++.h>
using namespace std;
// class representation of edge
class Edge {
    public:
    int source;
    int destination;
    int weight;
};
// function to find the top most parent of a vertex node
int findParent(int* parent, int node){
    if(node == parent[node]) return node;

    return findParent(parent, parent[node]);
} 
// we need to sort in increesing order based on the weight property
bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}
// Krushkels Algo
void  krushkels_algo(Edge* edges, int V, int E) {
    Edge* output = new Edge[V-1];
    // initially each node is a parent of itself
    int *parent = new int[V];
    for(int i=0; i<V; i++){
        parent[i] = i;
    }
    // sort the edges array based on weight of edges
    sort(edges, edges+E, compare);
    int count = 0;
    int i = 0;
    // start picking the edge from edges array and see if adding this mst makes a cycle or not
    while(count != V-1){
        Edge currentEdge = edges[i];
        int source = currentEdge.source;
        int destination = currentEdge.destination;
        int pSource = findParent(parent, source);
        int pdestination = findParent(parent, destination);
        if(pSource != pdestination){
            output[count] = currentEdge;
            count++;
            // either make pSource a child of pdestination or vica-versa
            // parent[pdestination] = pSource;
            parent[pSource] = pdestination;
        }
        i++;
    }

    //print MST
    for(int i=0; i<V-1; i++){
        // just to print in increesing order
        if (output[i].source < output[i].destination) {
            cout << output[i].source << " " << output[i].destination << " "
                 << output[i].weight << endl;
        } else {
             cout<<output[i].destination << " "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }

}
int main()
{
    int  V, E;
    cin>>V>>E;
    Edge *edges = new Edge[E];
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i].source = u;
        edges[i].destination = v;
        edges[i].weight = w;
    }

    krushkels_algo(edges, V, E);

    delete [] edges;
}
