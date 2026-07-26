class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0,time=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        if(!fresh)
            return 0;
        
        while(q.size()){
            int len=q.size();
            for(int k=0;k<len;k++){
                int i=(q.front()).first;
                int j=(q.front()).second;
                q.pop();
                if(i+1<m){
                    if(grid[i+1][j]==1){
                        grid[i+1][j]=2;
                        q.push({i+1,j});
                        fresh--;
                    }      
                }
                if(i>0){
                    if(grid[i-1][j]==1){
                        grid[i-1][j]=2;
                        q.push({i-1,j});
                        fresh--;
                    } 
                }
                if(j>0){
                    if(grid[i][j-1]==1){
                        grid[i][j-1]=2;
                        q.push({i,j-1});
                        fresh--;
                    } 
                }
                if(j+1<n){
                    if(grid[i][j+1]==1){
                        grid[i][j+1]=2;
                        q.push({i,j+1});
                        fresh--;
                    } 
                }
            }
            if(q.size())
                time++;
            
        }
        if(fresh)
            return -1;
        return time;
    }
};