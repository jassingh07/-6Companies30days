#include<bits/stdc++.h>
using namespace std;
class Solution {
    set<string> unique;
public:
    int maxUniqueSplit(string& s, int ind = 0) {
        if(ind == s.length()) return 0;
        string cur = "";
        int res = 0;
        for(int i = ind; i < s.length(); i++){
            cur.push_back(s[i]);
            if(unique.find(cur) == unique.end()){
                unique.insert(cur);
                res = max(res, 1 + maxUniqueSplit(s, i + 1));
                unique.erase(cur);//backtrack
            }
        }
        return res;
    }
};
int main()
{
   return 0;
}