/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* cur,int &ans){
        if(cur==NULL) return 0;
        
        int left = max(0,solve(cur->left,ans));
        int right = max(0,solve(cur->right,ans));
        
        ans = max(ans,cur->val+left+right);
        return max(left,right)+cur->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};
