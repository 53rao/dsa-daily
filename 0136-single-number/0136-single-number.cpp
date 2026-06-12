class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            if(prev==nums[i])
                count++;
            else{
                if(count==1)
                    return prev;
                else{
                    count=1;
                    prev=nums[i];
                }
            }
        }
        return prev;
    }
};