class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,h=nums.size()-1,tmp,i=0;
        while(i<=h){
            if(nums[i]==0){
                tmp = nums[i];
                nums[i] = nums[l];
                nums[l] = tmp;
                i++;
                l++;
            }
            else if(nums[i]==1) i++;
            else{
                tmp = nums[i];
                nums[i] = nums[h];
                nums[h] = tmp;
                h--;
            }
        }
    }
};
