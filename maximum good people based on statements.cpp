#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<bool> type;
    int n;
    int cnt = 0;
    void fun(int ind, vector<vector<int>>& st, int& maxGood){
        if(ind == n) {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++){
                    if(st[i][j] == 2) continue;
                    if(type[i] && (st[i][j] != type[j])) 
                        return;
                }//valid permutation
            int temp = 0;
            for(int i = 0; i < n; i++) temp += type[i];
            maxGood = max(maxGood, temp);
            return;
        }
        fun(ind + 1, st, maxGood);
        type[ind] = true;
        fun(ind + 1, st, maxGood);
        type[ind] = false;//backtrack
    }
public:
    int maximumGood(vector<vector<int>>& st) {
        int maxGood = 0;
        this -> n = st.size();
        type.resize(n, false);
        fun(0, st, maxGood);
        // cout << cnt << endl;
        return maxGood;
    }
};
int main()
{
   return 0;
}