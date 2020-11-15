class Solution {
public:
    bool solve(string s,int minlen, int maxlen, set<string> se, vector<int> &dp, int idx){
        if(idx == s.length()){
            return true;
        }
        if(dp[idx]==1) return true;
        if(dp[idx]==-1) return false;
        
        for(int i=minlen;i<=maxlen;i++){
            if(idx+i>s.length()) break;
            string str = s.substr(idx,i);
            if(!se.count(str)) continue;
            if(solve(s,minlen,maxlen,se,dp,idx+i)){
                dp[idx]=1;
                return true;
            }
        }
        dp[idx]=-1;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int minlen=INT_MAX,maxlen=0;
        
        for(string str : wordDict){
            int len = str.length();
            minlen = min(minlen,len);
            maxlen = max(maxlen,len);
        }
        
        set<string> se(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length(),0);
        return solve(s,minlen,maxlen,se,dp,0);
    }
};
