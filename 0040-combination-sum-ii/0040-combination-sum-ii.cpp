class Solution {
public:
    vector<vector<int>> soln;
    void combination(int idx,vector<int>& candidates,vector<int> &curr,int target,int total){
        if(total==target){
            soln.emplace_back(curr);
            return;
        }
        if(total>target||idx>=candidates.size())
            return;
        
        curr.emplace_back(candidates[idx]);
        combination(idx+1,candidates,curr,target,total+candidates[idx]);
        curr.pop_back();
        int i=idx;
        while(i<candidates.size()&&candidates[i]==candidates[idx])
            i++;
        combination(i,candidates,curr,target,total);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr={};
        sort(candidates.begin(),candidates.end());
        combination(0,candidates,curr,target,0);
        return soln;
    }
};