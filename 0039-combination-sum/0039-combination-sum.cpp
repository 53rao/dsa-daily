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
        for(int i=idx;i<candidates.size();i++){
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            backtrack(candidates,target,curr+candidates[i],i,temp);
            temp.pop_back();
        }
        
       
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates,target,0,0,temp);
        return soln;
    }
};