class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left=1,right=1,prev=nums[0],count=1;
        while(right<nums.size()){
            while(left<nums.size()&&nums[left]>prev){
                prev=nums[left];
                left++;
                count++;
            }
            right=left+1;
            while(right<nums.size()&&nums[right]<=prev)
                right++;
            if(right>=nums.size())
                break;
            nums[left]=nums[right];
            
            prev=nums[left];
            count++;
            left++;
        }
        return count;
    }
};