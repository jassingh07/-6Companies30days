#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto &s: tokens){
            if(s == "+"){
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(a + b);
            }
            else if(s == "*"){
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(a * b);
            }
            else if(s == "/"){
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(b / a);
            }
            else if(s == "-"){
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(b - a);
            }
            else nums.push(stoi(s));
        }

        return nums.top();
    }
};
int main()
{
   return 0;
}