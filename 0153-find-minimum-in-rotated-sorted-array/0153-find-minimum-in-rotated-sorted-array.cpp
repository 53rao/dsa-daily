class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,soln=5001;
        while(low<=high){
            mid=high-(high-low)/2;
            soln=min(nums[mid],soln);
            // sorted
            if(nums[low]<nums[mid]){
                // get the lowest and check the remaining array
                soln=min(nums[low],soln);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return soln;
    }
};