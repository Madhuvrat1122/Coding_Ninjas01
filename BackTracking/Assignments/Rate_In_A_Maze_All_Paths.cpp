// Problem statement
// You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).

// Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter into those cells and those with value 1 are open.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10
// 0 <= MAZE[i][j] <=1

// Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

// Time Limit: 1 sec
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 
// Explanation for Sample Output 1:
// Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >

// So our path matrix will look like this:

// 1 0 0
// 1 0 0
// 1 1 1

// Which is returned from left to right and then top to bottom in one line.
// Sample Input 2 :
// 2
// 1 0
// 0 1
// Sample Output 2 :
//  [Blank]
// Explanation for Sample Output 2:
// As no path is possible to the last cell, a blank vector will be returned and nothing is printed.

#include <bits/stdc++.h> 
bool isValid(vector<vector<int>> &arr, vector<vector<int>> &visited, int x, int y, int n){
    if(x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    
    if(visited[x][y] == 1 || arr[x][y] == 0) {
        return false;
    }
    
    return true;
}
void searchMazeHelper(vector<vector<int>> &arr, vector<vector<int>> &visited,  vector<vector<int>> &result, int x, int y, int n) {
    visited[x][y] = 1;

    if(x == n-1 && y == n-1){
        
        vector<int> path;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                path.push_back(visited[i][j]);
            }
        }
        result.push_back(path);
        visited[x][y] = 0;
        return;
    }
    
    if(isValid(arr, visited, x-1, y, n)){
        searchMazeHelper(arr, visited, result, x-1, y, n); // up   
    }
    
    if(isValid(arr, visited, x+1, y, n)){
        searchMazeHelper(arr, visited, result, x+1, y, n); // down  
    }
    
    if(isValid(arr, visited, x, y-1, n)){
        searchMazeHelper(arr, visited, result, x, y-1, n); // left  
    }
    
    if(isValid(arr, visited, x, y+1, n)){
        searchMazeHelper(arr, visited, result, x, y+1, n); // right
    }
    
    visited[x][y] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    int x = 0, y = 0;
    vector<vector<int>> visited(n, vector<int>(n,0));
    vector<vector<int>> result;
     // when start or end itself is block
    if(maze[0][0] == 0 | maze[n-1][n-1] == 0){
        return result;
    }
    searchMazeHelper(maze, visited, result, x, y, n);
    return result;
}
