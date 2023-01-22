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
class Solution {
    vlli dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        ll n = grid.size();
        MIN_HEAP(vlli) pq;
        pq.push({grid[0][0], 0, 0});//{value, {coordinates}}
        grid[0][0] = -1;//visited
        //start bfs types
        ll maxTime = 0;
        while(true){
            ll row = pq.top()[1], col = pq.top()[2];
            maxTime = max(maxTime, pq.top()[0]);
            if(row == n - 1 && col == n - 1) break;
            pq.pop();
            fl(i, 0, 4, 1){
                ll x = row + dx[i], y = col + dy[i];
                if(x < 0 ||x == grid.size() || y < 0 || y == grid[0].size() || grid[x][y] == -1) continue;
                pq.push({grid[x][y], x, y});
                grid[x][y] = -1;
            }
        }
        return maxTime;
    }
};
int main()
{
   return 0;
}