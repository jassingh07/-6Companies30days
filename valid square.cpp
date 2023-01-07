#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<int> s;

        for(int i = 0; i < 4; i++)
            for(int j = i + 1; j < 4; j++)
                s.insert( pow(points[j][1] - points[i][1], 2) + pow(points[j][0] - points[i][0], 2) );
       
        if(s.size() != 2) return false;
        return *s.rbegin() == 2 * (*s.begin());
    }
};

int main()
{
   return 0;
}