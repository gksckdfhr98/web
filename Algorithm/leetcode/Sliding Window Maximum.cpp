class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k==1) return nums;
        
        vector<int> ans;
        deque<int> dq;
        dq.push_back(nums[0]);
        for(int i=1;i<k;i++){
            while(!dq.empty() && nums[i]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[i]);
        }
        ans.push_back(dq.front());
        
        for(int i=0,j=k;j<nums.size();i++,j++){
            if(dq.front()==nums[i]) dq.pop_front();
            while(!dq.empty() && nums[j]>dq.back()){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            ans.push_back(dq.front());
        }
        return ans;
    }
};
