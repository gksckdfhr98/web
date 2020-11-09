class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> nums,vector<int> &tmp,int len,int idx){
        if(tmp.size() == len){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(ans,nums,tmp,len,i+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=0;i<=nums.size();i++){
            dfs(ans,nums,tmp,i,0);
        }
        
        return ans;
    }
};
