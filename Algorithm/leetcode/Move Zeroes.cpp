class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,cnt=0;
        while(i<nums.size()){
            if(cnt==nums.size())break;
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
            }
            else i++;
            cnt++;
        }
    }
};
