#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last;
        int res = 1e6;
        for(int i = 0; i < cards.size(); i++){
            if(last[cards[i]]) res = min(res, i - last[cards[i]] + 2);
            last[cards[i]] = i + 1;
        }
        return res == 1e6 ? -1 : res;
    }
};
int main()
{
   return 0;
}