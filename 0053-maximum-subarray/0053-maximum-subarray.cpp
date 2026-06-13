class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int soln=nums[0],curr=0;
        for(int num:nums){
            curr=max(num,num+curr);
            soln=max(curr,soln);
        }
        return soln;
    }
};