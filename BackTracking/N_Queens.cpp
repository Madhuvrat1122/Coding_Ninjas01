// Problem statement
// You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.

// A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'N' <= 10

// Time Limit: 1sec


// For Example:
// For a chessboard of size 4*4
// The configurations are 
// alt text

// Sample Input 1:
// 4
// Sample Output 1:
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// Explanation For Sample Input 1:
// Output depicts two possible configurations of the chessboard for 4 queens.

// The Chessboard matrix for the first configuration looks as follows:-

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
// Sample Input 2:
// 3
// Sample Output2:
//       (Blank)
// Explanation For Sample Input 2:
// Since no possible configuration exists for 3 Queen's.The output remains Empty.

#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<int>> &board, int n, int x, int y) {
    // check up side from current position
    for(int i=0; i<x; i++){
        if(board[i][y] == 1) return false;
    }
    // check top left daigonal
    for(int i=x,j=y; i>=0&&j>=0; i--,j--){
        if(board[i][j] == 1) return false;
    }
    // check top right daigonal
    for(int i=x,j=y; i>=0&&j<n; i--,j++){
        if(board[i][j] == 1) return false;
    }
    
    return true;
}
void solveNQueensHelper(vector<vector<int>> &board, vector<vector<int>> &output, int n, int row, int &counter){
    // Base case: placed all queens(0 to n-1)
    if(row == n){
        vector<int> curSolution;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                curSolution.push_back(board[i][j]);
                // output[counter].push_back(board[i][j]);
            }
        }
        output.push_back(curSolution);
        counter++; // count of solutions
        return;
    }
    // check all colummns of current row
    for(int j=0; j<n; j++){
        if(isValid(board, n, row, j)){
            board[row][j] = 1;
            solveNQueensHelper(board, output, n, row+1, counter); // move to new row
            board[row][j] = 0; // backtrack
        }   
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> output;
    int counter = 0;
    solveNQueensHelper(board, output, n, 0, counter); // start with 0th row
    return output;
}
int main()
{
    int n;
    cin >> n; // size of board
    vector<vector<int>> output = solveNQueens(n);
    
    // print all solutions
    for(int i=0; i<output.size(); i++){
        cout<<"Solution #"<<i+1<<endl;
        for(int j=0; j<output[i].size(); j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
