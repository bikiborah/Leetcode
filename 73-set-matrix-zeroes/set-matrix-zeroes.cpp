class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
         int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> temp=matrix;

        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){

            if(temp[i][j]==0){

              // left
              int a=i;
              int b=j;
              while(b>=0){
                matrix[a][b]=0;
                b--;
              }

              // right
              int c=i;
              int d=j;
              while(d<n){
                matrix[c][d]=0;
                d++;
              }

              // up
              int e=i;
              int f=j;
              while(e>=0){
                matrix[e][f]=0;
                e--;
              }

              // down
              int g=i;
              int h=j;
              while(g<m){
                matrix[g][h]=0;
                g++;
              }

            }
          }
        }
    }
};