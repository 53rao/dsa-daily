class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> soln(V);
        
        for(int i=0;i<edges.size();i++){
            soln[edges[i].first].emplace_back(edges[i].second);
            soln[edges[i].second].emplace_back(edges[i].first);
        }
        
        return soln;
    }
};