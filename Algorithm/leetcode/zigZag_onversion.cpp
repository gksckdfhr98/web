class Solution {
public:
    string convert(string s, int numRows) {
        vector<char> v[numRows];
        bool increase=true;
        int pos=0;
        
        if(numRows==1) return s;
        
        for(int i=0;i<s.length();i++){
            if(increase){
                if(pos<numRows){
                    v[pos].push_back(s[i]);
                    pos++;
                }
                else{
                    pos=numRows-2;
                    v[pos].push_back(s[i]);
                    pos--;
                    increase=false;
                }
            }
            else{
                if(pos>=0){
                    v[pos].push_back(s[i]);
                    pos--;
                }
                else{
                    pos=1;
                    v[pos].push_back(s[i]);
                    pos++;
                    increase=true;
                }
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<v[i].size();j++){
                ans+=v[i][j];
            }
        }
        return ans;
    }
};
