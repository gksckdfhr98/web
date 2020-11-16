class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses);
        vector<int> indegree(numCourses,0);
        
        for(auto v : prerequisites){
            edge[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int visited=0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            visited++;
            
            for(auto v : edge[cur]){
                if(--indegree[v]==0) q.push(v);
            }
        }
        
        return numCourses==visited;
    }
};
