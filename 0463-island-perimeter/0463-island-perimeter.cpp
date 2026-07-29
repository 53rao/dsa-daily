class Solution {
public:
    set<pair<int,int>> visited;
    void dfs(vector<vector<int>>& grid,int i,int j,int &soln){
        int count=0;
        visited.insert({i,j});
        if(i>0&&grid[i-1][j]==1){
            count++;
            if(!visited.count({i-1,j}))
                dfs(grid,i-1,j,soln);
        }
        if(j>0&&grid[i][j-1]==1){
            count++;
            if(!visited.count({i,j-1}))
                dfs(grid,i,j-1,soln);
        }
        if(i+1<grid.size()&&grid[i+1][j]==1){
            count++;
            if(!visited.count({i+1,j}))
                dfs(grid,i+1,j,soln);
        }
        if(j+1<grid[0].size()&&grid[i][j+1]==1){
            count++;
            if(!visited.count({i,j+1}))
                dfs(grid,i,j+1,soln);
        }
        soln+=(4-count);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int soln=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,soln);
                    return soln;
                }
            }
        }
        return 0;
    }
};