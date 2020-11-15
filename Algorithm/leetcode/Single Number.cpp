class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto n : nums){
            m[n]++;
        }
        int ans;
        for(auto n : nums){
            if(m[n]==1){
                ans=n;
                break;
            }
        }
        return ans;
    }
};
