class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> se;
        int n = s.length();
        int ans(0),i(0),j(0);
        while(i<n&&j<n){
            if(se.find(s[j]) == se.end()){
                se.insert(s[j]);
                int len = j-i+1;
                ans = max(ans,len);
                j++;
            }
            else{
                se.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
