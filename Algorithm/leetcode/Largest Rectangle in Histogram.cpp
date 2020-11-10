class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        int n = heights.size();
        stack< pair<int,int> > st;
        st.push({0,heights[0]});
        int idx,ans(0);
        for(int i=1;i<n;i++){
            idx=i;
            while(!st.empty() && st.top().second > heights[i]){
                idx = st.top().first;
                int h = st.top().second;
                st.pop();
                ans = max(ans,h*(i-idx));
            }
            st.push({idx,heights[i]});
        }
        while(!st.empty()){
            idx = st.top().first;
            int h = st.top().second;
            st.pop();
            ans = max(ans,h*(n-idx));
        }
        return ans;
    }
};
