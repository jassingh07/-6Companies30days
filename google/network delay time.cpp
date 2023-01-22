#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fl(i, m, n, p) for (ll i = m; i < n; i += p)
#define bl(i, m, n, p) for (ll i = m, i >= n; i -= p)
#define pb(a) push_back(a)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define vlli vector<ll>
#define vd vector<double>
#define si set<int>
#define MOD (ll)(1e9 + 7)
#define MOD2 (ll)(998244353)
#define plli pair<ll, ll>
#define testin ll t;  cin >> t; while (t--)
#define fel(x, v) for (auto x : v)
#define print(x, v) fel(x, v) cout << x << ' '
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vvi vector<vi>
#define vpi vector<pair<int, int>>
#define vplli vector<pair<ll, ll>>
#define pi pair<int, int>
#define vvlli vector<vlli>
#define vc vector<char>
#define vvc vector<vc>
#define vb vector<bool>
#define endl "\n"
#define MIN_HEAP(T) priority_queue<T, vector<T>, greater<T>>
#include <numeric>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vvlli> adj(n + 1);
        for(auto &v: times)
            adj[v[0]].push_back({v[1], v[2]});
        
        vlli dis(n + 1, 1e7);//1e7 == inf
        dis[src] = 0;
        MIN_HEAP(vlli) pq;//{dis, src}
        pq.push({0, src});

        while(pq.size()){
            ll minD = pq.top()[0];
            ll node = pq.top()[1];
            pq.pop();
            for(auto &neb: adj[node]){
                if(dis[neb[0]] > dis[node] + neb[1]) {
                    dis[neb[0]] = dis[node] + neb[1];
                    pq.push({dis[neb[0]], neb[0]});
                }
            }//end for loop
        }//end while
        // fl(i, 1, n + 1, 1) cout << dis[i] << " ";
        ll ans = *max_element(dis.begin() + 1, dis.end());
        return ans == 1e7 ? -1 : ans;
    }
};
int main()
{
   return 0;
}