class Solution {
  public:
    void bfs(int node,vector<vector<int>> &ll,vector<int> &visited){
        visited[node]=1;
        for(int i=0;i<ll[node].size();i++){
            if(!visited[ll[node][i]]){
                visited[ll[node][i]]=1;
                bfs(ll[node][i],ll,visited);
            }
        }
    }
    int countConnected(int V, vector<vector<int>> edges) {
        // code here
        int soln=0;
        vector<vector<int>> ll(V);
        vector<int> visited(V,0);

        for(int i=0;i<edges.size();i++){

            ll[edges[i][0]].emplace_back(edges[i][1]);
            ll[edges[i][1]].emplace_back(edges[i][0]);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,ll,visited);
                soln++;

            }
        }
        return soln;
    }
};