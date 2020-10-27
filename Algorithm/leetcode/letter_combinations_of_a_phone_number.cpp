class Solution {
public:
    void dfs(int idx,string digits,vector<string> &ans, map<char,string> &m,string s){
        if(idx == digits.length()){
            if(s!=""){
                ans.push_back(s);
            }
            return;
        }
        
        if(m.count(digits[idx])){
            for(char c : m.at(digits[idx])){
                string tmp=s;
                tmp+=c;
                dfs(idx+1,digits,ans,m,tmp);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> m ={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},
                               {'9',"wxyz"}};
        vector<string> ans;
        
        dfs(0,digits,ans,m,"");
        
        return ans;
    }
};
