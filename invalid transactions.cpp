#include<bits/stdc++.h>
#include <unordered_set>
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
    vector<string> parse(string& s){
            vector<string> v(4);
            stringstream st(s);
            
            int i = 0;
            while(st.good())
                getline(st, v[i++], ',');
            return v;
    }
public:
    vector<string> invalidTransactions(vector<string>& tr) {
        int n = tr.size();
        vector<string> res;

        vector<vector<string>> parsed;
        unordered_set<int> invalid;

        for(auto &s: tr) {
            vector<string> cur = parse(s);
            parsed.pb(cur);
        }

        for(int i = 0; i < n; i++){
            if(stoi(parsed[i][2]) > 1000) invalid.insert(i);
            fl(j, 0, n, 1){
                if(i == j) continue;

                if(parsed[i][0] == parsed[j][0] && parsed[i][3] != parsed[j][3] && abs( stoi(parsed[i][1]) - stoi(parsed[j][1]) ) <= 60) invalid.insert(i), invalid.insert(j);

            }
        }//end outer loop

        for(auto i: invalid)
            res.pb(tr[i]);

        return res;
    }//end fxn
};
int main()
{
   return 0;
}