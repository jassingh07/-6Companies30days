#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isPalindrome(int x, int base){
        vector<int> res;
        while(x){
            res.push_back(x % base);
            x /= base;
        }
        int i = 0, j = res.size() - 1;
        while(i <= j){
            if(res[i++] != res[j--]) return false;
        }
        return true;
    }
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n - 2; i++){
            if(!isPalindrome(n, i)) return false;
        }
        return true;
    }
};
int main()
{
   return 0;
}