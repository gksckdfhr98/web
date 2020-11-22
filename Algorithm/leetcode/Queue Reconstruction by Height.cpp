
bool cmp(vector<int> p1,vector<int> p2){
        if(p1[0] > p2[0]) return true;
        else if(p1[0]==p2[0]) return p1[1]<p2[1];
        else return false;
    }
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), cmp);
        for(vector<int> p : people){
            ans.insert(ans.begin()+p[1],p);
        }
        return ans;
    }
};
