#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &arr, vector<vector<int>> &visited, int x, int y, int n){
    if(x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }
    
    if(visited[x][y] == 1 || arr[x][y] == 0) {
        return false;
    }
    
    return true;
}
void searchMazeHelper(vector<vector<int>> &arr, vector<vector<int>> &visited, vector<string> &result, string &path, int x, int y, int n) {
    visited[x][y] = 1;

    if(x == n-1 && y == n-1){
        result.push_back(path);
        visited[x][y] = 0;
        path.pop_back();
        return;
    }
    
    if(isValid(arr, visited, x-1, y, n)){
        path += "U";
        searchMazeHelper(arr, visited, result, path, x-1, y, n); // up   
    }
    
    if(isValid(arr, visited, x+1, y, n)){
        path += "D";
        searchMazeHelper(arr, visited, result, path, x+1, y, n); // down  
    }
    
    if(isValid(arr, visited, x, y-1, n)){
        path += "L";
        searchMazeHelper(arr, visited, result, path, x, y-1, n); // left  
    }
    
    if(isValid(arr, visited, x, y+1, n)){
        path += "R";
        searchMazeHelper(arr, visited, result, path, x, y+1, n); // right
    }
    
    visited[x][y] = 0;
    path.pop_back();
}
vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    int x = 0, y = 0;
    vector<vector<int>> visited(n, vector<int>(n,0));
    vector<string> result;
    string path = "";
     // when start or end itself is block
    if(arr[0][0] == 0 | arr[n-1][n-1] == 0){
        return result;
    }
    searchMazeHelper(arr, visited, result, path, x, y, n);
    return result;
}
int main()
{
    vector<vector<int>> arr { { 1, 0, 0, 0 }, { 1, 1, 0, 0 }, { 1, 1, 0, 0}, { 0, 1, 1, 1} };
    int n = 4;
    vector<string> result = searchMaze(arr, n);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }

    return 0;
}
