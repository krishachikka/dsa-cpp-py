#include<bits/stdc++.h>
using namespace std;

//arbitrary queen should be safe horizontally and vertically and diagonally safe
bool isSafe(vector<string> &board, int row, int col, int n){
  //for checking horizontally
  for (int j= 0 ; j<n ; j++){
    if(board[row][j] == 'Q'){
      return false;
    }
  }
  //for checking vertically
  for (int i = 0 ; i < n; i++){
    if(board[i][col] == 'Q'){
      return false;
    }
  }
  //for checking left diagonally left
  for(int i = row, j = col; i >= 0 && j >= 0 ; i--, j--){
    if(board[i][j] == 'Q'){
      return false;
    }
  }
  //for checking left diagonally right
  for(int i = row, j = col; i >= 0 && j < n ; i--, j++){
    if(board[i][j] == 'Q'){
      return false;
    }
  }
  return true;
};


void nQueens(vector<string> &board, int row, int n , vector<vector<string>> &sol){
  //Base case for the recursive function
  if(row == n){
    sol.push_back(board);
    return;
  }
  
  //check in all possible columns:
  for (int j = 0; j< n; j++){
    if(isSafe(board, row, j, n)){
      //place the queen if possible
      board[row][j] = 'Q';
      //recursive call for next box
      nQueens(board, row+1, n, sol);
      //if we come backtracking replace the Added Q with '.' to delete that pathway
      board[row][j] = '.';
    }
  }
};

vector<vector<string>> solveNQueens(int n){
  vector<string> board(n,string(n,'.'));
  vector<vector<string>> sol;
  
  nQueens(board, 0, n, sol);
  
  return sol;
};


int main(){
    int n;
    cin>>n;
    
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << endl;
        }
        cout << endl;
    }


    return 0;
}
