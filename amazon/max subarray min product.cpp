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

ll log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
class sparse{//rsq
    vvlli st;
    ll k;
    public:
    sparse(vi& v){
        ll n = v.size();
        k = log2_floor(n) + 1;
        st.resize(n, vlli(k));
        fl(i, 0, n, 1) st[i][0] = v[i];//base
        fl(i, 1, k, 1)
            for(ll j = 0; j + (1 << i) - 1 < n; j++)
                st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    ll query(ll l, ll r){//l,r -> 0 based indexing
        return min(st[l][log2_floor(r - l + 1)], st[r + 1 - (1 << log2_floor(r - l + 1))][log2_floor(r - l + 1)]);
    }
};

class Solution {
    
public:
    int maxSumMinProduct(vector<int>& nums) {
        ll res = 0, n = nums.size();
        sparse s(nums);
        vlli pref(n, 0); pref[0] = nums[0];
        fl(i, 1, n, 1) pref[i] += pref[i - 1] + nums[i];
        for(int i = 0; i < n; i++){
            ll cur = 0;
            int low = 0, high = i, mid, l;
            while(low <= high){
                mid = (low + high) / 2;
                if(s.query(mid, i) == nums[i]) {
                    high = mid - 1;
                    l = mid;
                }
                else low = mid + 1;
            }
            cur += pref[i] - (l ? pref[l - 1] : 0);
            low = i; high = n - 1; 
            ll r;
            while(low <= high){
                mid = (low + high) / 2;
                if(s.query(i, mid) == nums[i]){
                    low = mid + 1;
                    r = mid;
                }
                else high = mid - 1;
            }
            cur += (r > i ? pref[r] - pref[i] : 0);
            // cout << cur << endl;
            res = max(res, cur * nums[i]);
        }
        return res % MOD;
    }
};
int main()
{
   return 0;
}