class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()),mid,soln=INT_MAX;
        while(low<=high){
            mid=high-(high-low)/2;
            int count=0;
            for(auto it:nums){
                count+=(it+mid-1)/mid;
            }
            if(count<=threshold){
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