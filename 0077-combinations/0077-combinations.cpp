class Solution {
public:
    
    void backtrack(int n,int k,int size,vector<int> &temp,vector<vector<int>> &soln){
        if(size==k){
            soln.emplace_back(temp);
            return;
        }
        for(int i=temp.size()?temp.back()+1:1;i<=n;i++){
            temp.emplace_back(i);
            backtrack(n,k,size+1,temp,soln);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> soln;
        vector<int> temp;
        backtrack(n,k,0,temp,soln);
        return soln;
    }
};