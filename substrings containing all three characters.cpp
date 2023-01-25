#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
    bool all(vector<int>& f){
        return f[0] && f[1] && f[2];
    }
public:
    int numberOfSubstrings(string s) {
        ll n = s.length();
        //sliding window
        ll comp = 0;//compliement subarrays
        ll till = -1;
        ll last = 0;
        vector<int> f(3, 0);
        for(int i = 0; i < n; i++){
            f[s[i] - 'a']++;
            while(all(f))
                f[s[last++] - 'a']--;
            
            comp += (i - last + 1) * (i - last + 2) / 2;
            if(till >= last) comp -= (till - last + 1) * (till - last + 2) / 2;
            till = i;
        }
        return n * (n + 1) / 2 - comp;
        // cout << comp;
    }
};
int main()
{
   return 0;
}