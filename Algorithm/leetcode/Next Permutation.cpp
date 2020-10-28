class Solution {
public:
    void reverse(vector<int> &nums,int start){
        int j = nums.size()-1;
        while(start<j){
            swap(nums,start,j);
            start++;
            j--;
        }
    }
    
    void swap(vector<int> &nums,int i,int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j = nums.size()-1;
            while(j>=i && nums[j]<=nums[i]) j--;
            swap(nums,i,j);
        }
        reverse(nums,i+1);
    }
};
