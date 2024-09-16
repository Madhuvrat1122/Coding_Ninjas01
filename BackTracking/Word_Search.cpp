// Problem statement
// You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.

// Your task is to return true if the given word exists in the grid, else return false. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
// Note:
// The same letter cell should not be used more than once.
// For Example:
// For a given word “design” and the given 2D board 
// [[q’, ‘v’, ‘m’, ‘h’],
//  [‘d’, ‘e’, ‘s’, ‘i’],
//  [‘d’, ‘g’, ‘f’, ‘g’],
//  [‘e’, ‘c’, ‘p’, ‘n’]]

// The word design can be formed by sequentially adjacent cells as shown by the highlighted color in the 2nd row and last column.


#include <iostream>
#include <vector>
using namespace std;
bool isValid(int n, int x, int m, int y, vector<vector<int>> &visited, int index, vector<vector<char>> &board, string &word){
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    if(visited[x][y] == 1 || board[x][y] != word[index]) return false;
    return true;
}
void presentHelper(int n, int x, int m, int y, vector<vector<int>> &visited, int index, vector<vector<char>> &board, string &word, bool &result) {
    visited[x][y] = 1;
 
    if(index == word.length()-1){
        visited[x][y] = 0;
        result = true;
        return;
    }
    
    //up
    if(isValid(n, x-1, m, y, visited, index+1, board, word)){
        presentHelper(n, x-1, m, y, visited, index+1, board, word, result);
    }
    //down
    if(isValid(n, x+1, m, y, visited, index+1, board, word)){
        presentHelper(n, x+1, m, y, visited, index+1, board, word, result);
    }
    //left
    if(isValid(n, x, m, y-1, visited, index+1, board, word)){
        presentHelper(n, x, m, y-1, visited, index+1, board, word, result);
    }
    //right
    if(isValid(n, x, m, y+1, visited, index+1, board, word)){
        presentHelper(n, x, m, y+1, visited, index+1, board, word, result);
    }
    
    visited[x][y] = 0;
}
bool present(vector<vector<char>> &board, string &word, int n, int m) 
{
    vector<vector<int>> visited(n,vector<int>(m,0));
    bool result = false;
    // finding out the index from where to start
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                presentHelper(n, i, m, j, visited, 0, board, word, result);
                if(result){
                    return result;
                }
            }
        }
    }
    
    // If Reach Here means there is not word available
    return result;
}
int main()
{
    vector<vector<char>> board {{ 'c', 'z', 'k', 'l' }, 
                                { 'o', 'd', 'i', 'a' }, 
                                { 'r', 'g', 'n', 'm' }, 
                                { 'm', 'r', 's', 'd' }};
    int n = 4, m = 4;
    string word = "coding";
    if(present(board, word, n, m)){
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    
    return 0;
}
