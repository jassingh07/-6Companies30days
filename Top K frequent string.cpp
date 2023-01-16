#include<bits/stdc++.h>
using namespace std;
// class Compare{
//     public:
//         bool operator()(pair<int, string>& a, pair<int, string>& b){
//             return a.first != b.first ? a.first > b.first : a.second < b.second;
//         }//jehre heap ch thalle retain hon onha di property likhni hundi aa
//     //fer soch max heap ch a < b hi houga na 
// };

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> fr;
        for(auto &s: words)
            fr[s]++;
        priority_queue<pair<int, string>> maxh;

        for(auto p: fr) {
            maxh.push({-p.second, p.first});
            if(maxh.size() > k) maxh.pop();
        }
        //lexicographically vi sort hojange equal freq vale te vaise vi - lagake nahi tn kathe ovein sort nahi si ho rahe

        vector<string> res(k);
        int ind = k - 1;
        while(maxh.size()){
            res[ind--] = maxh.top().second;
            maxh.pop();
        }
        return res;
    }
};
int main()
{
   return 0;
}