#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<bool> vis;

    void update_amount(vector<vector<int>>& adj, vector<int> &ds, vector<int>& amount, int bob, int node = 0){
        vis[node] = true;

        ds.push_back(node);
        if(node == bob) {
            int n = ds.size();

            for(int i = n - 1; i >= n - n/2; i--) {
                amount[ds[i]] = 0;
                // cout << ds[i] << " ";
            }
            // cout << ds[n / 2] << " ";
            if(n % 2) amount[ds[n / 2]] /= 2;
        }
        for(auto neb: adj[node]){
            if(!vis[neb]) update_amount(adj, ds, amount, bob, neb);
        }

        ds.pop_back();
    }
    int dfs(vector<vector<int>>& adj, vector<int>& amount, int node = 0){
        int res = -1e9;
        vis[node] = true;

        // cout << node << " ";

        for(auto neb: adj[node])
            if(!vis[neb]) res = max(res, dfs(adj, amount, neb));
        
        return (res == -1e9 ? 0 : res) + amount[node];
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        for(auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> ds;
        vis.resize(n, false);
        update_amount(adj, ds, amount, bob);

        for(int i = 0; i < n; i++) vis[i] = false;
        return dfs(adj, amount);
    }
};
int main()
{
   return 0;
}