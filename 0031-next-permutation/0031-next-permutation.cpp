class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int high=nums.size()-1,low=nums.size()-2,prev=nums[high];
        while(low>=0){
            if(nums[low]<prev){
                int curr=nums[low+1],idx=low+1;
                for(int i=low;i<=high;i++){
                    if(nums[i]>nums[low]&&curr>nums[i]){
                        curr=nums[i];
                        idx=i;
                    }
                }
                swap(nums[low],nums[idx]);
                sort(nums.begin()+low+1,nums.end());
                return;
            }
            prev=nums[low];
            low--;
        }
        sort(nums.begin(),nums.end());
    }
};