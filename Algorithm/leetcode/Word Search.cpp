class Solution {
public:
    void dfs(vector<vector<char>> board,vector<vector<bool>> &flag,string word,bool &ans,int idx,int x,int y){
        if(idx == word.size()){
            ans = true;
            return;
        }
        if(ans) return;
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || nx >= board.size() || ny<0 || ny>= board[0].size() || flag[nx][ny]) continue;
            if(word[idx] == board[nx][ny]){
                flag[x][y]=true;
                dfs(board,flag,word,ans,idx+1,nx,ny);
                flag[x][y] = false;
            }
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=false;
        int row = board.size();
        int col = board[0].size();
        vector< pair<int,int> > start;
        vector<vector<bool>> flag(row,vector<bool>(col,0));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == word[0]) start.push_back({i,j});
            }
        }
        
        if(start.size()==0) return false;
        
        for(int i=0;i<start.size();i++){
            int x = start[i].first;
            int y = start[i].second;
            dfs(board,flag,word,ans,1,x,y);
        }
        
        return ans;
    }
};
