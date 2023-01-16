#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string& order, string& s) {
        unordered_map<char, int> pos;
        for(int i = 0; i < order.length(); i++)
            pos[order[i]] = i;
        sort(s.begin(), s.end(), [&](char a, char b){
            return pos[a] < pos[b];
        });
        return s;
    }
};
int main()
{
   return 0;
}