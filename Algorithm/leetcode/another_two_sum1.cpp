class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(m.count(complement)){
                ans.push_back(i);
                ans.push_back(m[complement]);
                return ans;
            }
            m.insert({nums[i],i});
        }
        return ans;
    }
};
