class Solution {
public:
    void solve(vector<vector<char>> grid,vector<vector<bool>> &visited,int x,int y){
        queue< pair<int,int> > q;
        q.push({x,y});
        visited[x][y]=true;
        
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx = r + dx[i];
                int ny = c + dy[i];
                
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()) continue;
                if(grid[nx][ny]=='1' && !visited[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    solve(grid,visited,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
