class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxn=INT_MIN,cur=1;
        for(int i=0;i<nums.size();i++){
            cur *= nums[i];
            maxn = max(maxn,cur);
            if(nums[i]==0) cur=1;
        }
        cur=1;
        for(int i=nums.size()-1;i>=0;i--){
            cur *= nums[i];
            maxn = max(maxn,cur);
            if(nums[i]==0) cur=1;
        }
        return maxn;
    }
};
