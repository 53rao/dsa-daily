class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> soln;
        for(int num:nums){
            if(num!=0){
                soln.emplace_back(num);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i<soln.size()){
                nums[i]=soln[i];
            }
            else{
                nums[i]=0;
            }
        }
    }
};