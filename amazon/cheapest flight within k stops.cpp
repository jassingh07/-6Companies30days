#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<vector<int>>> adj;
    vector<vector<int>> dp;
    int dst;
    int dfs(int node, int k){
        if(k < 0) return 1e6;
        if(node == dst){
            return 0;
        }
        if(dp[node][k] != -1) return dp[node][k];
        int res = 1e6;
        for(auto &neb: adj[node]){
            res = min(res, neb[1] + dfs(neb[0], k - 1));
        }
        return dp[node][k] = res;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.resize(n);
        dp.resize(n, vector<int>(k + 2, -1));
        this -> dst = dst;
        for(auto &v: flights)
            adj[v[0]].push_back({v[1], v[2]});
        int res = dfs(src, k + 1);
        return res == 1e6 ? -1 : res;
    }
};
int main()
{
   return 0;
}