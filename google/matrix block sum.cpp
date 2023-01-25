#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i = 1; i < col; i++) mat[0][i] += mat[0][i - 1];
        for(int i = 1; i < row; i++)
            {   
                for(int j = 1; j < col; j++) mat[i][j] += mat[i][j - 1];
                for(int j = 0; j < col; j++) mat[i][j] += mat[i - 1][j];
            }
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                int rc = min(j + k, col - 1);
                int dr = min(i + k, row - 1);
                int lc = max(0, j - k);
                int ur = max(0, i - k);
                ans[i][j] = mat[dr][rc] - (lc > 0 ? mat[dr][lc - 1] : 0) - (ur > 0 ? mat[ur - 1][rc] : 0) + (ur > 0 && lc > 0 ? mat[ur - 1][lc - 1] : 0);
            }
        return ans;
    }
};
int main()
{
   return 0;
}