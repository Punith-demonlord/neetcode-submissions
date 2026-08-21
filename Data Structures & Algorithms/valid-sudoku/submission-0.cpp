//we should check for its row ,its column and the 3*3 matrix it is in
// checking row and column easy follow standard method can be done in n^2 time period we need to correctly identify and check in 3*3 matrix for which we can use hashmap 
#include <string>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9];
        int col[9][9];
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++) {
                row[i][j]=0;
                col[i][j]=0;
            }
        }
        
        int mat[3][3][9];
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++) {
                for (int k=0;k<9;k++) {
                mat[i][j][k]=0;
                }
            }
        }
        //row checking
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                if (board[i][j]=='.') {continue;}
                if (row[i][(board[i][j])-'1']==1||col[j][board[i][j]-'1']==1||mat[i/3][j/3][board[i][j]-'1']==1) {
                    return false;
                } 
                row[i][(board[i][j])-'1']=1;
                col[j][(board[i][j])-'1']=1;
                mat[i/3][j/3][(board[i][j])-'1']=1;
            }
            
        }
    return true;
    }
};
