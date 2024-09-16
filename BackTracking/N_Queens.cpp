// Problem statement
// Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:

// (a, b) -> (a + b, b)
// (a, b) -> (a, a + b)
// Your task is to find if it is possible to reach the destination point using only the desired moves or not.

// For example:
// For the coordinates, source point = (1, 1) and destination point = (3, 5)
// The output will be true as the destination point can be reached using the following sequence of moves:
// (1, 1) -> (1, 2) -> (3, 2) -> (3, 5)
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 100
// 1 <= x, y <= 3000

// Where ‘T’ is the number of test cases and ‘x’, ‘y’ are the coordinates of the given points.

// Time Limit: 1sec
// Sample Input 1:
// 2
// 1 1 3 5
// 1 1 1 4
// Sample Output 1:
// True
// True
// Explanation For Sample Input 1:
// For the first test case
// The output will be true as destination point can be reached using the following sequence of moves:
// (1, 1) -> (1, 2) -> (3, 2) -> (3, 5)

// For the second test case
// The output will be true as destination point can be reached using the following sequence of moves:
// (1, 1) -> (1, 2) -> (1, 3) -> (1, 4)
// Sample Input 2:
// 2
// 1 1 2 2
// 1 1 1 1
// Sample Output 2:
// False
// True
// bool reachDestination(int sx, int sy, int dx, int dy) {
//     // Write your code here
// }

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
