class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0),mid,curr,count,soln=high;
        
        while(low<=high){
            mid=low+(high-low)/2;
            count=0;
            curr=0;
            for(int i=0;i<nums.size();i++){
                curr+=nums[i];
                if(curr>mid){
                    curr=nums[i];
                    count++;
                }
            }
            if(count+1<=k){
                soln=min(soln,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return soln;
        
    }
};