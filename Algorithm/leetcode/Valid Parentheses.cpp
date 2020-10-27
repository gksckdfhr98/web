class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            else{
                char c = st.top();
                if(c=='(' && s[i]==')') st.pop();
                else if(c=='[' && s[i]==']') st.pop();
                else if(c=='{' && s[i]=='}') st.pop();
                else st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
