#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string& s) {
        queue<int> rq, dq;
        int n = s.length();
        for(int i = 0; i < n; i++)
            if(s[i] == 'R') rq.push(i);
            else dq.push(i);
        while(rq.size() && dq.size()){
            if(rq.front() > dq.front()) dq.push(dq.front() + n);
            else rq.push(rq.front() + n);
            rq.pop();
            dq.pop();
        }
        return rq.size() ? "Radiant" : "Dire";
    }
};        
int main()
{
   return 0;
}