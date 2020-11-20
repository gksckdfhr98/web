class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tot=1;
        int cnt=0;
        vector<int> ans;
        for(auto n : nums){
            if(n==0) cnt++;
            else tot*=n;
        }
        if(cnt>=2){
            for(int i=0;i<nums.size();i++) ans.push_back(0);
        }
        else if(cnt==1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0) ans.push_back(tot);
                else ans.push_back(0);
            }
        }
        else{
            for(int i=0;i<nums.size();i++){
                ans.push_back(tot/nums[i]);
            }
        }
        return ans;
    }
};
