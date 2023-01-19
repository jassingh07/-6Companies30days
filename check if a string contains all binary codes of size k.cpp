#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> m;
        // cout << (int)s.length() - k;
        for(int i = 0; i <= (int)s.length() - k; i++){
            m.insert(s.substr(i, k));
        }
        return m.size() == pow(2, k);
    }
};
int main()
{
   return 0;
}