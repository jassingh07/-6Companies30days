#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool neg = false;
        int n = matrix.size();
        ll sum = 0;
        ll minVal = 1e5;
        bool zero = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] < 0)  neg = !neg;
                minVal = min(minVal, (ll)abs(matrix[i][j]) );
                if(!matrix[i][j]) zero = true;
                sum += abs(matrix[i][j]);
            }
            // cout << maxNeg;
        return neg && !zero ? sum - 2 * minVal : sum;
    }
};
int main()
{
   return 0;
}