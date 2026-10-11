class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> store(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = c - 1; j >= 0; j--) {
                store[j][r - 1 - i] = matrix[i][j];
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = store[i][j];
            }
        }
    }
};
