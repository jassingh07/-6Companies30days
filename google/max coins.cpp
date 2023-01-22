#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0, n = piles.size();
        for(int i = n / 3; i < n; i += 2) res += piles[i];
        return res;
    }
};
int main()
{
   return 0;
}