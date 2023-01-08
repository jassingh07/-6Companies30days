#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pr, vector<int>& cap) {
        vector<pair<int, int>> v;
        int n = pr.size();
        for(int i = 0; i < n; i++) v.push_back({cap[i], pr[i]});
        sort(v.begin(), v.end());
        
        priority_queue<int> pq;//max heap of profits whose capital <= w
        
        int i = 0;
        while(k--){
            while(i < n && v[i].first <= w) {
                pq.push(v[i].second);
                i++;
            }
            if(!pq.size()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
int main()
{
   return 0;
}