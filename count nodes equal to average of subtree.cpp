#include<bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    int res = 0;
    vector<int> postorder(TreeNode* root){
        if(!root) return {0, 0};
        vector<int> left = postorder(root -> left);
        vector<int> right = postorder(root -> right);
        res += (left[0] + right[0] + root -> val)/ (1 + left[1] + right[1]) == root -> val;
        return {left[0] + right[0] + root -> val, 1 + left[1] + right[1]};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return res;
    }
};
int main()
{
   return 0;
}