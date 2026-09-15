class Solution {
public:
    bool checker(vector<vector<char>>& board, string &word,int m,int n,int idx,int x,int y){
        if(idx==word.size())
            return true;
        if(x<0 || y<0 || x>=m || y>=n || word[idx]!=board[x][y])
            return false;
        char temp=board[x][y];
        board[x][y]='#';
        bool soln= (checker(board,word,m,n,idx+1,x+1,y)||
                    checker(board,word,m,n,idx+1,x-1,y)||
                    checker(board,word,m,n,idx+1,x,y+1)||
                    checker(board,word,m,n,idx+1,x,y-1));
        board[x][y]=temp;
        return soln;
       
    }
    bool exist(vector<vector<char>>& board, string word) {
        char start=word[0];
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==start){
                    if(checker(board,word,board.size(),board[0].size(),0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};