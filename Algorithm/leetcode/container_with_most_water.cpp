// broute force

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea=0;
        for(int i=0;i<height.size()-1;i++){
            for(int j=i+1;j<height.size();j++){
                maxarea = max(maxarea, min(height[i],height[j])*(j-i));
            }
        }
        return maxarea;
    }
};

