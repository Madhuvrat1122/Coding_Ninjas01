// Problem statement
// You are given a reference/address of a node in a connected undirected graph containing N nodes and M edges. You are supposed to return a clone of the given graph which is nothing but a deep copy. Each node in the graph contains an integer “data” and an array/list of its neighbours.

// The structure of the graphNode class is as follows:

// class graphNode 
// {  
//     public:
//         int data;
//         vector<graphNode*> neighbours;
// }
// Note :
// 1. Nodes are numbered from 1 to N.

// 2. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 5
// 2 <= N <= 100000
// 1 <= M <= min(N(N-1)/2,100000)
// 1 <= E[i][0], E[i][1] <= N

// Where  ‘N’ is the number of nodes in the given graph, ‘M’ denotes the number of edges and ‘E’ denotes the edge matrix.

// Time Limit: 1 sec.
// Sample Input 1 :
// 2
// 5
// 6
// 1 2
// 4 1
// 2 4
// 3 4
// 5 2
// 1 3
// 3
// 2
// 1 2
// 1 3
// Sample Output 1 :
// true
// true
// Explanation of Input 1 :
// In the first test case, the returned graph contains 5 nodes and 6 edges which are:
// 1 2
// 4 1
// 2 4
// 3 4
// 5 2
// 1 3
// Since it is similar to the given graph with different address nodes then the solution is correct.

// In the second test case, the returned graph contains 3 nodes and 2 edges which are:
// 1 2
// 1 3
// Since it is similar to the given graph with different address nodes then the solution is correct.
// Sample Input 2 :
// 2
// 5
// 4
// 1 2
// 2 3
// 3 4
// 4 5
// 2
// 1
// 1 2
// Sample Output 2 :
// true
// true
// Explanation of Input 2 :
// In the first test case, the returned graph contains 5 nodes and 4 edges which are:
// 1 2
// 2 3
// 3 4
// 4 5
// Since it is similar to the given graph with different address nodes then the solution is correct.

// In the second test case, the returned graph contains 2 nodes and 1 edge which is:
// 1 2

// Since it is similar to the given graph with different address nodes then the solution is correct.



#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
	if (node == nullptr) return nullptr;

    queue<graphNode*> pendingNodes;
	unordered_map<graphNode*, graphNode*> isVisited;

	graphNode* clonnedNode = new graphNode(node->data);
	isVisited[node] = clonnedNode;
	pendingNodes.push(node);

	while(!pendingNodes.empty()){
		graphNode* front = pendingNodes.front();
		pendingNodes.pop();

		//copy the neighbourse of node to clonnedNode
		for(graphNode* neighbour : front->neighbours){
			// it means neighbour not visisted yet
			if(isVisited.find(neighbour) == isVisited.end()){
				//create new node
				graphNode* newNode = new graphNode(neighbour->data);
				isVisited[neighbour] = newNode;
				pendingNodes.push(neighbour);
			}
			isVisited[front]->neighbours.push_back(isVisited[neighbour]); // copying the neighbour to new node's neighbours
		}	
	
	}

	return clonnedNode;
}
