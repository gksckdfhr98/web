//top-down

class Solution {
public:
    int dfs(vector<int> coins,int amount,vector<int> &dp){
        if(amount<0) return -1;
        if(amount==0) return 0;
        if(dp[amount-1]!=0) return dp[amount-1];
        
        int min = INT_MAX;
        
        for(auto n : coins){
            int res = dfs(coins,amount-n,dp);
            if(res>=0 && res<min){
                min = res + 1;
            }
        }
        dp[amount-1] = (min==INT_MAX) ? -1 : min;
        return dp[amount-1];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0;
        vector<int> dp(amount,0);
        
        return dfs(coins,amount,dp);
    }
};

// bottom-up

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(coins.size()==1 && coins[0] > amount) return -1;
        
        vector<int> dp(amount+1,INT_MAX);
        
        for(auto coin : coins){
            if(coin <= amount){
                dp[coin]=1;
            }
        }
        
        for(int i=1;i<=amount;i++){
            for(auto coin : coins){
                if(coin <=i && dp[i-coin]!=INT_MAX){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
