// Problem statement
// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= N <= 1000
// 2 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 3 4
// AAAA
// ABCA
// AAAA
// Sample Output 1:
// true
#include <iostream>
#include <vector>
using namespace std;
int dx[] = {-1, 1, 0, 0};  // Movement in x-direction: up, down
int dy[] = {0, 0, -1, 1};  // Movement in y-direction: left, right
bool dfs(char **matrix, vector<vector<bool>> &visited, int x, int y, int fromx, int fromy, char color, int len, int n, int m){
    visited[x][y] = true;

    //explore all direction
    for(int i=0; i<4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newY >=0 && newX < n && newY < m ){
            if(matrix[newX][newY] == color){
                // If the new cell is not the cell we came from
                if(fromx != newX || fromy  != newY){
                    // If the new cell is already visited and the path length is at least 4, we found a cycle
                    if (visited[newX][newY]) {
                        if (len >= 4) return true;
                    } else {
                        // Continue DFS to the new cell
                        if (dfs(matrix, visited, newX, newY, x, y, color, len+1, n, m)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool hasCycle(char **matrix, int n, int m) {
    // Initialize visited array to keep track of visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Iterate through each cell in the board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is not visited yet, start DFS from that cell
            if (!visited[i][j]) {
                if (dfs(matrix, visited, i, j, -1, -1, matrix[i][j], 1, n, m)) {
                    return true;  // If a cycle is found, return true
                }
            }
        }
    }

    return false;  // No cycle found in the entire grid
}
int main()
{
    int n,m;
    cin>>n>>m;
    
    char **matrix = new char*[n];
    for(int i=0; i<n; i++){
        matrix[i] = new char[m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    if(hasCycle(matrix, n, m)){
        cout<<"true";
    } else {
        cout<<"false";
    }

    return 0;
}
