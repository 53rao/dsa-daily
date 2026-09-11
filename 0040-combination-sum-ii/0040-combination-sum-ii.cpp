class Solution {
public:
    vector<vector<int>> soln;
    
    void backtrack(vector<int>& candidates, int &target,int idx,int curr,vector<int> &temp){
        if(curr==target){
            soln.emplace_back(temp);
            return;
        }
        if(idx>=candidates.size()||curr>target)
            return;
        // include
        temp.emplace_back(candidates[idx]);
        backtrack(candidates,target,idx+1,curr+candidates[idx],temp);
        temp.pop_back();
        int k=candidates[idx];
        while(idx<candidates.size()&&k==candidates[idx]){
            idx++;
        }
        backtrack(candidates,target,idx,curr,temp);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,0,temp);
        return vector<vector<int>>(soln.begin(),soln.end());
    }
};