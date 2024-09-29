// Problem statement
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

// There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 1000
// 1 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output 1:
// 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}; // up, down, left, right, top-left, top-right, bottom-left, bottom-right
string target = "CODINGNINJA";
bool DFS(char **matrix, vector<vector<bool>>& visited, int x, int y, int idx, int n, int m){
    // base case
    if(idx == target.size()) return true;
    visited[x][y] = true;

    // Explore all 8 directions
    for (int i = 0; i < 8; ++i) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check if new coordinates are within bounds and not visited
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && !visited[newX][newY] && matrix[newX][newY] == target[idx]) {
            if (DFS(matrix, visited, newX, newY, idx + 1, n, m)) {
                return true;  // If the path is found, return true
            }
        }
    }

    //backtrack
    visited[x][y] = false;
    return false;
}
bool isPath(char **matrix, int n, int m){
    vector<vector<bool>> visited(n, vector<bool>(m, false));  // To track visited cells
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 'C'){
                if(DFS(matrix, visited, i,  j, 1, n, m)){
                    return true;
                }
            }
        }
    }

    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;

    char **matrix = new char*[n];
    for(int i=0; i<n; i++){
        matrix[i] = new char[m];
    }

    //take edge input
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<isPath(matrix, n, m);

    //deallocate memory
    for(int i=0; i<n; i++){
        delete [] matrix[i];
    }
}
