class Solution {
public:
    void backtracking(vector<int>& nums,int idx,int curr,int &soln){
        if(idx>=nums.size()){
            soln+=curr;
            return;
        }
        backtracking(nums,idx+1,curr,soln);
        curr=curr^nums[idx];
        backtracking(nums,idx+1,curr,soln);
    }
    int subsetXORSum(vector<int>& nums) {
        int soln=0;
        backtracking(nums,0,0,soln);
        return soln;
    }
};