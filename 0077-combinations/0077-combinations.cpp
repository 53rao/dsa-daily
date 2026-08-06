class Solution {
public:
    void comb(int n,int k,int index,vector<int> &curr,set<vector<int>> &soln){
        if (curr.size() == k) {
            soln.insert(curr);
            return;
        }
        if (index > n) {
            return;
        }
        curr.emplace_back(index);
        comb(n, k, index + 1, curr, soln);
        curr.pop_back(); 
        comb(n,k,index+1,curr,soln);
    }
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> soln;
        vector<int> temp;
        comb(n,k,1,temp,soln);
        return vector<vector<int>>{soln.begin(),soln.end()};
    }
};