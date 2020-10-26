class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int maxlength=0;
        int start=0;
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            maxlength=1;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                maxlength=2;
                start=i;
            }
        }
        
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k + 1;i++){
                int j = i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                    start = i;
                    if(k>maxlength) maxlength=k;
                }
            }
        }
        string ans = s.substr(start,maxlength);
        return ans;
    }
};
