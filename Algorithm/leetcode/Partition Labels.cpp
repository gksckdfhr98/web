class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        map<char,int> m;
        for(int i=0;i<S.length();i++){
            char c = S[i];
            m[c] = i;
        }
        int i=0,j=m[S[i]],start=0;
        while(i<S.length() && j<S.length()){
            while(i<j){
                if(m[S[i]]>j) j=m[S[i]];
                i++;
            }
            ans.push_back(j-start+1);
            if(i==S.length()-1)break;
            i++;
            start=i;
            j=m[S[i]];
        }
        return ans;
    }
};
