#include<bits/stdc++.h>
using namespace std;
class Solution {
    // bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& dfsvis, int node)
    // {
    //     vis[node] = true;
    //     dfsvis[node] = true;
    //     bool res = false;// no cycle assumed
    //     for(auto neb: adj[node])
    //     {
    //         if(dfsvis[neb]) return true;
    //         if(!vis[neb]) 
    //             res |= dfs(adj, vis, dfsvis, neb);
    //     }
    //     dfsvis[node] = false;//backtrack
    //     return res;
    // }
public:
    bool canFinish(int n, vector<vector<int>>& edge) {//detect cycle in a graph
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto& v: edge)
        {
            //let's make a directed graph which is more sensible
            adj[v[1]].push_back(v[0]);//prerequisite -> course edge
            indegree[v[0]]++;
        }
        vector<int> toposort;
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!indegree[i])
                q.push(i);

        while(q.size()){
            int top = q.front();
            toposort.push_back(top);
            for(auto neb: adj[top]){
                if(indegree[neb]) {
                    indegree[neb]--;
                    if(!indegree[neb]) q.push(neb);
                }
            }
            q.pop();
        }
        return toposort.size() == n;
        
    }
};
int main()
{
   return 0;
}