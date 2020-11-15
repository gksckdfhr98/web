class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> se;
        int minn=INT_MAX;
        for(auto n : nums){
            se.insert(n);
            if(minn > n) minn=n;
        }
        int maxn=0,cnt=0;
        for(auto it=se.begin();it!=se.end();it++){
            int num = *it;
            if(num-minn==1 || num==minn){
                minn=num;
                cnt++;
            }
            else{
                maxn = max(maxn,cnt);
                cnt=1;
                minn=num;
            }
        }
        maxn = max(maxn,cnt);
        return maxn;
    }
};
