// linear search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) ans=i;
        }
        return ans;
    }
};

//binary search

class Solution {
public:
    int binarysearch(vector<int> &nums,int low,int high,int target){
        if(high<low) return -1;
        
        int mid = low + (high-low)/2;
        
        if(nums[mid]==target) return mid;
        
        if(nums[low]<=nums[mid]){
            if(nums[low]<=target && target<=nums[mid])
                return binarysearch(nums,low,mid-1,target);
            return binarysearch(nums,mid+1,high,target);
        }
        // low에서 mid 사이는 오름차순이 아님.
        if(nums[mid]<=target && target<=nums[high])
            return binarysearch(nums,mid+1,high,target);
        return binarysearch(nums,low,mid-1,target);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = binarysearch(nums,0,n-1,target);
        return ans;
    }
};
