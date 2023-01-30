#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int cnt = 0, n = s.length();
        vector<vector<int>> pos(26);
        for(int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
        for(auto &w: words){
            int i = 0;
            bool res = true;
            for(auto c: w){
                int ind = lower_bound(pos[c - 'a'].begin(), pos[c - 'a'].end(), i) - pos[c - 'a'].begin();
                if(ind == pos[c - 'a'].size()) {
                    res = false;
                    break;
                }
                i = pos[c - 'a'][ind] + 1;
            }
            cnt += res;
        }
        return cnt;
    }
};
int main()
{
   return 0;
}