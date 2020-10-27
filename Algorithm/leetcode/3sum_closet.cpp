class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=9876543;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j,k;
        
        while(i<len-2){
            j=i+1;k=len-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    return sum;
                }
                if(abs(sum-target)<abs(ans-target)){
                    ans = sum;
                }
            }
            i++;
        }
        
        return ans;
    }
};
