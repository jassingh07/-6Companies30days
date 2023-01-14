#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        ll num = numerator;
        ll den = denominator;
        bool pos = (num / abs(num) == den / abs(den));
        num = abs(num);
        den = abs(den);
        string decimal = to_string(num / den);
        string fraction = ".";
        ll rem = num % den;
        unordered_map<ll, ll> m;

        while(rem){
            ll div = rem * 10 / den;
            if(m[rem * 10]) {
                // cout << rem << " ";
                int ind = m[rem * 10];//previous occuring index
                fraction.push_back(')');
                fraction.insert(ind, "(");
                break;
            }
            else m[rem * 10] = fraction.length();

            fraction.push_back((char)(div + '0'));
            // cout << div << " " << rem << endl;
            rem = rem * 10 % den;
        }

        if(!pos) decimal.insert(0, "-");
        return decimal + (fraction.size() > 1 ? fraction : "");
    }
};

int main()
{
   return 0;
}