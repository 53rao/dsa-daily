class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0,soln=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                soln=max(soln,curr);
                curr=0;
            }
            else{
                curr++;
            }
        }
        return max(soln,curr);
    }
};