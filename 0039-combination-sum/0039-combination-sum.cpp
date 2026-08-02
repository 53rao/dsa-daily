class Solution {
public:
    vector<vector<int>> soln;
    void combination(int idx,vector<int>& candidates,vector<int> &curr,int target,int total){
        if(total==target){
            soln.emplace_back(curr);
            return;
        }
        if(total>target||idx==candidates.size())
            return;
        curr.emplace_back(candidates[idx]);
        combination(idx,candidates,curr,target,total+candidates[idx]);
        curr.pop_back();
        combination(idx+1,candidates,curr,target,total);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr={};
        combination(0,candidates,curr,target,0);
        return soln;
    }
};