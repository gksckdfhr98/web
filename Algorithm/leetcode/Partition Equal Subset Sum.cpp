class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot=0;
        for(auto n : nums) tot+=n;
        if(tot%2!=0) return false;
        int subsum = tot/2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(subsum+1,0));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            int cur = nums[i-1];
            for(int j=0;j<=subsum;j++){
                if(j<cur){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j] || dp[i-1][j-cur];
                }
            }
        }
        return dp[n][subsum];
    }
};
