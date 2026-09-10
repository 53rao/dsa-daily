class Solution {
public:
    vector<vector<int>> soln;
    void backtrack(vector<int>& candidates, int target,int curr,int idx,vector<int> &temp){
        if(curr==target){
            soln.emplace_back(temp);
            return;
        }
        if(idx>=candidates.size()|| curr>target)
            return;
        // case 1 : skip and move forward
        backtrack(candidates,target,curr,idx+1,temp);
        // case 2: include and  dont move forward
        temp.emplace_back(candidates[idx]);
        
        backtrack(candidates,target,curr+candidates[idx],idx,temp);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates,target,0,0,temp);
        return soln;
    }
};