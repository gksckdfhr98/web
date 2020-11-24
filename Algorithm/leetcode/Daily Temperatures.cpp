class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && T[st.top()] < T[i]){
                int idx = st.top();
                ans[idx] = i-idx;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx = st.top();
            ans[idx] = 0;
            st.pop();
        }
        return ans;
    }
};
