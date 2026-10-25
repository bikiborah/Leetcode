class Solution {
public:
   bool SatisfyRules(int row,int col,char digit,vector<vector<char>> &board){
    int startR = (row/3)*3;
    int StartC = (col/3)*3;


    for(int i = 0; i < 9; i++){
      //  ROW CHECK
      if(board[row][i] == digit){
        return false;
      }
      // COL CHECK
      if(board[i][col] == digit){
        return false;
      }

      // sub board check
      if(board[startR + i/3][StartC + i%3] == digit){
        return false;
      }
    }

    return true;
   }

    bool solve(vector<vector<char>> &board){
      for(int i = 0; i < 9;i ++){
        for(int j = 0; j < 9; j++){
          if(board[i][j] == '.'){
            for(char digit= '1'; digit <= '9'; digit++){
              if(SatisfyRules(i,j,digit,board)){
                board[i][j] = digit;
                bool val = solve(board);
                if(val == true){
                  return true;
                }
                board[i][j] = '.';
              }
            }
            return false;
          }
        }
      }
      return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
        //your code goes here
        solve(board);      
    }
};