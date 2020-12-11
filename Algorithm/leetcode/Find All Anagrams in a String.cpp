class Solution {
public:
    bool isana(map<char,int> &ma){
        for(auto it : ma){
            if(it.second) return false;
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        if(n<m) return ans;
        map<char,int> ma;
        for(int i=0;i<m;i++){
            ma[p[i]]++;
        }
        int left=0;
        for(int i=0;i<n;i++){
            ma[s[i]]--;
            if(i-left+1>m){
                ma[s[left]]++;
                left++;
            }
            if(i-left+1==m && isana(ma)) ans.push_back(left);
        }
        return ans;
    }
};
