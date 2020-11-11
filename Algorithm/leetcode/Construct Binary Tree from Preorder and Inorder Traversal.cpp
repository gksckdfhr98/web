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
    int idx=0;
    TreeNode* solve(vector<int>& pre,vector<int>& in,int s,int e){
        if(s>e) return NULL;
        
        TreeNode *root = new TreeNode(pre[idx]);
        idx++;
        
        if(s==e) return root;
        
        int newidx=0;
        for(int i=s;i<=e;i++){
            if(in[i]==root->val){
                newidx=i;
                break;
            }
        }
        
        root->left = solve(pre,in,s,newidx-1);
        root->right = solve(pre,in,newidx+1,e);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *ans = solve(preorder,inorder,0,preorder.size()-1);
        return ans;
    }
};
