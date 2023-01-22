#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last = 0, res = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < fruits.size();i++){
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[last]]--;
                if(!m[fruits[last]]) m.erase(fruits[last]);
                last++;
            }
            res = max(res, i - last + 1);
        }
        return res;
    }
};
int main()
{
   return 0;
}