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

//two pointer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea(0),i(0),j(height.size()-1);
        while(i<j){
            maxarea = max(maxarea, min(height[i],height[j])*(j-i));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxarea;
    }
};

