#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creator, vector<string>& ids, vector<int>& views) {
        unordered_map<string, ll> tv;//Total Views for creator
        unordered_map<string, pair<ll, string>> mvid;//Most Viewed Id for creater
        ll mviews = 0;
        for(int i = 0; i < views.size(); i++){
            tv[creator[i]] += views[i];
            mviews = max(mviews, tv[creator[i]]);
            if(!mvid[creator[i]].second.length() || views[i] > mvid[creator[i]].first) mvid[creator[i]] = {views[i], ids[i]};
            else if(views[i] == mvid[creator[i]].first && ids[i] < mvid[creator[i]].second){
                mvid[creator[i]] = {views[i], ids[i]};
            }
        }
        vector<vector<string>> res;
        for(auto &p: tv){
            if(p.second == mviews){
                vector<string> cur;
                cur.push_back(p.first);
                cur.push_back(mvid[p.first].second);
                res.push_back(cur);
            }
        }
        return res;
    }
};
int main()
{
   return 0;
}