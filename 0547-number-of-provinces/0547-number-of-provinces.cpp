class Solution {
public:
    void bfs(int n,vector<vector<int>>& isConnected,vector<int> &visited){
        visited[n]=1;
        for(int i=0;i<isConnected.size();i++){
            if(i==n)
                continue;
            else if(!visited[i]&&isConnected[n][i]){
                bfs(i,isConnected,visited);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int soln=0;
        vector<int> visited(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++)
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                bfs(i,isConnected,visited);
                soln++;
            }
        }
        return soln;
    }
};