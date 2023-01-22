#include<bits/stdc++.h>
using namespace std;
class Solution {
    int res = 0;
    bool dfs(vector<vector<int>>& grid, int i, int j){
        int row = grid.size(), col = grid[0].size();
        if(i < 0 || i >= row || j < 0 || j >= col) return false;
        if(grid[i][j]) return true;

        grid[i][j] = 1;
        return dfs(grid, i + 1, j) & dfs(grid, i - 1, j) & dfs(grid, i, j - 1) & dfs(grid, i, j + 1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(!grid[i][j] && dfs(grid, i, j)) res++;
        return res;
    }
};
int main()
{
   return 0;
}