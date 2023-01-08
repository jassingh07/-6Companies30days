#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dis(vector<int>& a, vector<int>& b){
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++){
            unordered_map<int, int> m;//dis, number of points at this dis

            for(int j = 0; j < n; j++){
                m[dis(points[i], points[j])]++;
            }//hashing

            for(auto p: m){
                res += p.second * (p.second - 1);
            }
            //end checking all j's and k's
        }//end checking all i's
        //{i, j, k} tuple di gal kar rea
        return res;
    }
    

};
int main()
{
   return 0;
}