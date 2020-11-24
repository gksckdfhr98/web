class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = n;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=1;len<=n;len++){
            for(int i=0;i<n-len;i++){
                dp[i][i+len] = (s[i]==s[i+len] && (dp[i+1][i+len-1] || len==1));
                if(dp[i][i+len]) ans++;
            }
        }
        return ans;
    }
};
