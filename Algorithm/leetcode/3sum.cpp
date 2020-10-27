class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len<3){
            return vector<vector<int>>();
        }
        
        set<vector<int>> result_set;
        sort(nums.begin(),nums.end());
        int i=0,j,k;
        while(i<len-2){
            j=i+1,k=len-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    result_set.insert({nums[i],nums[j++],nums[k--]});
                }
            }
            i++;
        }
        
        return vector<vector<int>>(result_set.begin(),result_set.end());
    }
};
