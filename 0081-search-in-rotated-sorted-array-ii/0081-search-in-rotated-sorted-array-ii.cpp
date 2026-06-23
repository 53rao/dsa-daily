class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=high-(high-low)/2;
            
            if(nums[mid]==target)
                return true;
            // low to mid is sorted
            if(nums[low]<nums[mid]){
                // in that range
                if(nums[low]<=target&&target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }   
            // mid to end is sorted
            else if(nums[low]>nums[mid]){
                if(nums[mid]<target&&target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else
                low++;
        }
        return false;
    }
};