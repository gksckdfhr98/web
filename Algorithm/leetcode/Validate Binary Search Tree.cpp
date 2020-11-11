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
    bool dfs(TreeNode* cur,long low,long high){
        if(cur==NULL) return true;
        
        if(cur->val <= low || cur->val >= high) return false;
        
        return dfs(cur->left,low,cur->val) && dfs(cur->right,cur->val,high);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        return dfs(root,LONG_MIN,LONG_MAX);
        
    }
};
