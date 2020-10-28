class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> se;
        for(auto i : nums){
            se.insert(i);
        }
        
        nums = vector<int>(se.begin(),se.end());
        
        return se.size();
    }
};
