class Solution {
public:
    int solve(int n, vector<int> &dp, vector<int> &mul){
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(auto m : mul){
            if(m>n) break;
            ans = min(ans,solve(n-m,dp,mul)+1);
        }
        dp[n]=ans;
        return ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        vector<int> mul;
        for(int i=1;i*i<=n;i++){
            dp[i*i]=1;
            mul.push_back(i*i);
        }
        
        
        return solve(n,dp,mul);
    }
};
