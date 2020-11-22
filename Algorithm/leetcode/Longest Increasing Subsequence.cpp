class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int n = nums.size();
        int ans=0;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            int j=i-1;
            while(j>=0){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
                j--;
            }
            ans = max(ans,dp[i]);
        } 
        return ans;
    }
};
