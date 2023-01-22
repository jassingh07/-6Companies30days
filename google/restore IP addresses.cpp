#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
    vector<string> res;
    void fun(int ind, int part,string& s, string ds){
        if(part == 4){
            if(ind == s.length() || (s[ind] == '0' && ind < s.length() - 1) || s.length() - ind > 3) return;

            int suff = stoi(s.substr(ind, s.length() - ind));
            if(suff > 255) return;
            res.push_back(ds + to_string(suff));
            return;
        }
        string cur = "";
        for(int i = ind; i <= min(ind + 3, (int)s.length() - 1); i++){
            if(cur == "0") return;
            cur.push_back(s[i]);
            if(stoi(cur) > 255) return;
            fun(i + 1, part + 1, s, ds + cur + ".");
        }
    }
public:
    vector<string> restoreIpAddresses(string& s) {
        string ds;
        fun(0, 1, s, ds);
        return res;
    }
};
int main()
{
   return 0;
}