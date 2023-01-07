#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<float, float>, set<pair<int, int>>> lines;//{slope, intercept} -> set of{xi, yi}
        int n = points.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                float denom = points[j][0] - points[i][0];
                float m, c;
                if(denom != 0) {
                m =  (points[j][1] - points[i][1]) / denom;
                c = points[j][1] - m * points[j][0];
                }
                else {
                    m = 1e9;
                    c = - points[j][0];
                }
                pair<float, float> family = {m, c};
                pair<int, int> a = {points[j][0], points[j][1]};
                pair<int, int> b = {points[i][0], points[i][1]};
                lines[family].insert(a);
                lines[family].insert(b);
            }
        int res = 1;
        for(auto p: lines){
            // cout << p.first.first << " " << p.first.second << " " << p.second.size() << endl;
            res = max(res, (int)p.second.size());
        }

        return res;
    }
};
int main()
{
   return 0;
}