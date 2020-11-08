class Solution {
public:
    int solve(int** dp,string word1,string word2, int m,int n){
        if(!m || !n) return m+n;
        if(word1[m-1]==word2[n-1]) return solve(dp,word1,word2,m-1,n-1);
        else{
            if(dp[m][n]) return dp[m][n];
            else{
                dp[m][n] = 1 + min(min(solve(dp,word1,word2,m-1,n),solve(dp,word1,word2,m,n-1)),solve(dp,word1,word2,m-1,n-1));
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int** dp = new int*[m+1];
        for(int i=0;i<m+1;i++){
            dp[i] = new int[n+1];
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        
        return solve(dp,word1,word2,m,n);
    }
};
