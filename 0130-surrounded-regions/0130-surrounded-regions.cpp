class Solution {
public:
    void bfs(set<pair<int,int>>& s,vector<vector<char>>& board,pair<int,int> x){
        auto [i,j]=x;
        if(i>0){

            if(!s.count({i-1,j})&&board[i-1][j]=='O'){
                s.insert({i-1,j});
                bfs(s,board,{i-1,j});
            }
        }
        if(j>0){

            if(!s.count({i,j-1})&&board[i][j-1]=='O'){
                s.insert({i,j-1});
                bfs(s,board,{i,j-1});
            }
        }
        if(i+1<board.size()){
            if(!s.count({i+1,j})&&board[i+1][j]=='O'){
                s.insert({i+1,j});
                bfs(s,board,{i+1,j});
            }
        }
        if(j+1<board[0].size()){
            if(!s.count({i,j+1})&&board[i][j+1]=='O'){
                s.insert({i,j+1});
                bfs(s,board,{i,j+1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        set<pair<int,int>> s;
        int m=board.size(),n=board[0].size();
        int x=0,y=0,count=0;
        if(m==1||n==1)
            return ;
        for(int i=0;i<m;i+=(m-1)){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    if(!s.count({i,j})){
                        bfs(s,board,{i,j});
                        s.insert({i,j});
                    }
                }
            }
        }
        for(int i=0;i<n;i+=(n-1)){
            for(int j=0;j<m;j++){
                if(board[j][i]=='O'){
                    if(!s.count({j,i})){
                        s.insert({j,i});

                        bfs(s,board,{j,i});
                    }

                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!s.count({i,j})){
                    board[i][j]='X';
                }
            }
        }
    }
};