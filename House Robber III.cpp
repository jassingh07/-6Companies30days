#include<bits/stdc++.h>
using namespace std;
#define ll           long long int

  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
    unordered_map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dp[root]) return dp[root];

        int take = root -> val + (root -> left ? rob(root -> left -> left) + rob(root -> left -> right): 0) + (root -> right ? rob(root -> right -> left)  + rob(root -> right -> right): 0);
        int not_take = rob(root -> left) + rob(root -> right);

        return dp[root] = max(take, not_take);
    }
};
int main()
{
   return 0;
}