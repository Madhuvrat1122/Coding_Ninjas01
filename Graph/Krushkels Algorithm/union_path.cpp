// Problem statement
// You have been given an undirected graph with 'N' vertices and 'M' edges. The vertices are labelled from 1 to 'N'.

// Your task is to find if the graph contains a cycle or not.

// A path that starts from a given vertex and ends at the same vertex traversing the edges only once is called a cycle.

// Example :
// In the below graph, there exists a cycle between vertex 1, 2 and 3. 
//   Note:

// 1. There are no parallel edges between two vertices.

// 2. There are no self-loops(an edge connecting the vertex to itself) in the graph.

// 3. The graph can be disconnected.
// For Example :

// Input: N = 3 , Edges =  [[1, 2], [2, 3], [1, 3]].
// Output: Yes

// Explanation : There are a total of 3 vertices in the graph. There is an edge between vertex 1 and 2, vertex 2 and 3 and vertex 1 and 3. So, there exists a cycle in the graph. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= N <= 5000
// 0 <= M <= min(5000, (N * (N - 1)) / 2)
// 1 <= edges[i][0] <= N 
// 1 <= edges[i][1] <= N 

// Time Limit: 1 sec 
// Sample Input 1:
// 1
// 3 2
// 1 2
// 2 3
// Sample output 1:
// No
// Explanation of Sample output 1:
//  The above graph can be represented as 
// Example

// There are a total of 3 vertices in the graph.There is an edge between vertex 1 and 2 and vertex 2 and 3. So, there is no cycle present in the graph. 
// Sample Input 2:
// 2
// 4 0 
// 4 3
// 1 4
// 4 3
// 3 1
// Sample output 2:
// No
// Yes

#include <iostream>
using namespace std;
class Edge {
    public:
    int source;
    int destination;
};
int findParent(int* parent, int node){
    if(node == parent[node]) return node;

    return findParent(parent, parent[node]);
} 
bool hasCycle(Edge *edges, int e, int v){
    int *parent = new int[v+1];
    // initially every node is parent of itself
    for(int i=1; i<=v; i++){
        parent[i] = i;
    }

    for(int i=0; i<e; i++){
        Edge currentEdge = edges[i];
        int s = currentEdge.source;
        int d = currentEdge.destination;
        // find the parent of source and destination
        int parentS = findParent(parent, s);
        int parentD = findParent(parent, d);
        // if both parent matched then there is a cycle
        if(parentS == parentD) return true;
        else {
            // make parentS parent of parentD or vica-versa
            // parent[parentD] = parentS;
            parent[parentS] = parentD;
        }
    }

    return false;
}
int main()
{
    int t, V, E;
    cin>>t;
    while(t--){
        cin>>V>>E;
        Edge *edges = new Edge[E];
        for(int i=0; i<E; i++){
            int u, v;
            cin>>u>>v;
            edges[i].source = u;
            edges[i].destination = v;
        }

        if(hasCycle(edges, E, V)){
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;;
        }
    }
}
