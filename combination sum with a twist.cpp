#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int n, int k, vector<int>& ds, vector<vector<int>>& res, int ind = 1){
        if(n < 0) return;
        if(ind > 9){
            if(k || n) return;
            res.push_back(ds);
            return;
        }
        
        ds.push_back(ind);
        dfs(n - ind, k - 1, ds, res, ind + 1);
        ds.pop_back();

        dfs(n, k, ds, res, ind + 1);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ds;
        dfs(n, k, ds, res);
        return res;
    }
};
int main()
{
   return 0;
}