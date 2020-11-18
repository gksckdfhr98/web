class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int i,int j,int idx){
        if(idx==word.size()-1) return true;
        
        int m = board.size();
        int n = board[0].size();
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        bool flag=false;
        board[i][j]-=32;
        
        for(int k=0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
            if(board[nx][ny]==word[idx+1] && dfs(board,word,nx,ny,idx+1)){
                flag=true;
                board[i][j]+=32;
                return true;
            }
        }
        if(!flag)
            board[i][j]+=32;
        return false;
    }
    
    bool exist(vector<vector<char>>& board,string &word){
        if(word.empty()) return true;
        int m = board.size();
        int n = board[0].size();
        int k = word.size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(k==1 || dfs(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(words.empty() || board.empty()) return ans;
        
        for(auto w : words){
            if(exist(board,w)) ans.push_back(w);
        }
        return ans;
    }
};
