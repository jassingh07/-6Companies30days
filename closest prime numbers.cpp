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
    vi sieve(int n, int left)
 {
    vector<bool> res(n+1,true);
    for(ll i=2;i<n+1;i++)
     for(ll j=i*i;j<=n;j+=i)
        res[j]=false;
    
    vi prime;
    fl(i, max(left, 2), n + 1, 1) if(res[i]) prime.pb(i);
    return prime;
 }

public:
    vector<int> closestPrimes(int left, int right) {
        vi ans = {-1, -1};
        vi prime = sieve(right, left);
        if(prime.size() <= 1) return ans;
        ans[0] = prime[0]; ans[1] = prime[1];
        
        fl(i, 2, prime.size(), 1){
            if(prime[i] - prime[i - 1] < ans[1] - ans[0]) {
                ans[0] = prime[i - 1];
                ans[1] = prime[i];
            }
        }
        // cout << ans.size();
        return ans;
    }
};
int main()
{
   return 0;
}