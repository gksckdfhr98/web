class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minn = nums.size();
        int maxn = 0;
        vector<int> tmp(nums.begin(),nums.end());
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=tmp[i]){
                minn = min(minn,i);
                maxn = max(maxn,i);
            }
        }
        return maxn >= minn ? (maxn-minn+1) : 0;
    }
};
