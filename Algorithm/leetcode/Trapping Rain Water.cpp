class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        int left_max=0,right_max=0;
        while(i<j){
            if(height[i]<height[j]){
                height[i]>=left_max ? left_max=height[i] : ans+= left_max-height[i];
                i++;
            }
            else{
                height[j]>=right_max ? right_max=height[j] : ans+= right_max-height[j];
                j--;
            }
        }
        return ans;
    }
};
