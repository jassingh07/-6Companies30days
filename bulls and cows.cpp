#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> real(10, 0), possible(10, 0);
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.length(); i++)
            if(secret[i] == guess[i]) 
                bulls++;
            else 
                real[secret[i] - '0']++, possible[guess[i] - '0']++;
        for(int i = 0; i < 10; i++)
            cows += min(real[i], possible[i]);
            
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
int main()
{
   return 0;
}