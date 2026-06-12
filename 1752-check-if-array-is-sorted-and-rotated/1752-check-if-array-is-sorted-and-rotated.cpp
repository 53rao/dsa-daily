class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0,prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<prev){
                if(count==1)
                    return false;
                count++;
            }
            prev=nums[i];       
        }
        if(nums[0]<prev){
            if(count==1)
                return false;
        }
        return true;
    }
};