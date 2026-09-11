class Solution {
public:
    void backtrack(vector<int>& candidates, int target,int curr,int idx,vector<int> &temp,vector<vector<int>> &soln
){
        if(curr==target){
            soln.emplace_back(temp);
            return;
        }
        if(idx>=candidates.size()|| curr>target)
            return;
        // case 1 : skip and move forward
        backtrack(candidates,target,curr,idx+1,temp,soln);
        // case 2: include and  dont move forward
        temp.emplace_back(candidates[idx]);
        
        backtrack(candidates,target,curr+candidates[idx],idx,temp,soln);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> soln;
        backtrack(candidates,target,0,0,temp,soln);
        return soln;
    }
};