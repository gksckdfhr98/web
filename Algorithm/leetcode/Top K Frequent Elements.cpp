class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()) return vector<int>();
        if(nums.empty()) return vector<int>();
        vector<int> ans;
        map<int,int> m;
        for(auto n : nums){
            m[n]++;
        }
        priority_queue< pair<int,int> > pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
