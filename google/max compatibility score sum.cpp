#include<bits/stdc++.h>
using namespace std;
class Solution {
    int ans = 0;
    int n;
    vector<bool> vis;
    int score(vector<int>& a, vector<int>& b){
        int res = 0;
        for(int i = 0; i < a.size(); i++) res += a[i] == b[i];
        return res;
    }
    void fun(vector<vector<int>>& st, vector<vector<int>>& mt,int ind, int cur){
        //cur = current compatibility score
        if(ind == n) {
            ans = max(ans, cur);
            return;
        }
        for(int i = 0; i < mt.size(); i++){
            if(vis[i]) continue;
            vis[i] = true;
            fun(st, mt, ind + 1,cur + score(st[ind], mt[i]) );
            vis[i] = false;
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students.size();
        vis.resize(n, false);
        fun(students, mentors, 0, 0);
        return ans;
    }
};
int main()
{
   return 0;
}