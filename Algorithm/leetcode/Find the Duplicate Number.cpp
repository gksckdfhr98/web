class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(auto n : nums){
            m[n]++;
        }
        int ans;
        for(auto it : m){
            if(it.second>1) ans = it.first;
        }
        
        return ans;
    }
};
