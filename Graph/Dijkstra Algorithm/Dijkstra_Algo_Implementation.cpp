// Problem statement
// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.

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
// Sample Output 1 :
// 0 0
// 1 3
// 2 4
// 3 5
#include <iostream>
#include <climits>
using namespace std;
// method to find the minimum un-visited vertex
long findMinVertex(long *distance, bool *visited, long v){
    long minVertex = -1;
    for(long i=0; i<v; i++){
        if(!visited[i] && (minVertex == -1 || distance[minVertex] > distance[i])){
            minVertex = i;
        }
    }
    return minVertex;
}
// print the cost at each vertex from source
void dijkstra(long **edges, long v){
    long* distance = new long[v];
    bool* visited = new bool[v];
    // intiall assign the distance for each vertex from source is maximum and visited is false
    for(long i=0; i<v; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    // Not since source in our case is 0 so distance from source to source is 0
    distance[0] = 0;
    
    // we can go till v-1 as there will no neighbours left for last vertex
    for(long i=0; i<v-1; i++){
        // find the minimum unvisited vertex
        long minVertex = findMinVertex(distance, visited, v);
        /// mark the current vertex as visited
        visited[minVertex] = true;
        // explore all its neighbours
        for(long j=0; j<v;  j++){
            // find neighbour with the help of matrix and should not be visited yet
            if(edges[minVertex][j] != 0 && !visited[j]){
                long curr_distance = distance[minVertex] + edges[minVertex][j];
                if(curr_distance < distance[j]){
                    distance[j] = curr_distance;
                }
            }
        }
    }

    //print the distance at each vertex from source
    for(long i=0; i<v; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

    //deallocate the memory for visited and distance array
    delete [] distance;
    delete [] visited;
}
int main() {
    long v, e;
    cin>>v>>e;
    //adjancy matrix
    long **edges = new long*[v];
    for(long i=0; i<v; i++){
        edges[i] = new long[v];
        for(long j=0; j<v; j++){
            edges[i][j] = 0; // currently no edges deines for any vertex
        }
    }
    // edges input
    for(long i=0; i<e; i++){
        long s, d, w;
        cin>>s>>d>>w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    cout<<endl;

    //dijkstra algorithm
    dijkstra(edges, v);

    //deallocate the edge's memeory
    for(long i=0; i<v; i++){
        delete [] edges[i];
    }
    delete [] edges;
}
