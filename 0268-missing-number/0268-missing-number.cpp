class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int curr=0;
        for(int num:nums){
            if(curr!=num)
                return curr;
            curr++;
        }
        return curr;
    }
};