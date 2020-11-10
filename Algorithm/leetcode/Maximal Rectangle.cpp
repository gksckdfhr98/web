class Solution {
public:
    int solve(vector<vector<int>> map,int y,int r_size){
        int res=0;
        stack< pair<int,int> > st;
        st.push({0,map[0][y]});
        int idx;
        for(int i=1;i<r_size;i++){
            idx=i;
            while(!st.empty() && st.top().second > map[i][y]){
                idx = st.top().first;
                int h = st.top().second;
                st.pop();
                res = max(res, h*(i-idx));
            }
            st.push({idx,map[i][y]});
        }
        while(!st.empty()){
            idx = st.top().first;
            int h = st.top().second;
            st.pop();
            res = max(res, h*(r_size-idx));
        }
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int ans=0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> map(n,vector<int>(m,0));
        int cnt;
        for(int i=0;i<n;i++){
            cnt=0;
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]=='1'){
                    map[i][j] = matrix[i][j]-'0' + cnt;
                    cnt++;
                }
                else cnt=0;
            }
        }
        int result;
        for(int i=0;i<m;i++){
            result = solve(map,i,n);
            ans = max(ans,result);
        }
        
        return ans;
    }
};
