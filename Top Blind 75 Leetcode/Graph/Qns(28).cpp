// Problem:- https://leetcode.com/problems/course-schedule/description/
class Solution {
public:
    // Kahn's Algorithm -> Topological sort using bfs
    // Ref:- https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
    // Intor to Topological Sort:- https://www.geeksforgeeks.org/topological-sorting/
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // contructing the in-degree vector for each vertex
        vector<int> in_degree(numCourses, 0);
        for(auto pre: prerequisites){
            int course = pre[0];
            int prerequisite = pre[1];
            in_degree[course]++;
        }
        // create adjascent vector
        vector<vector<int>> adj(numCourses);
        for(auto e: prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        // push all vertex with 0 in degree into queue;
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            for(auto neighbour: adj[front]){
                in_degree[neighbour]--;
                if(in_degree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }

        return count == numCourses;
    }
};
