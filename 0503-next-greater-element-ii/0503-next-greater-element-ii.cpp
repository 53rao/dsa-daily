class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> soln;
        for(int i=0;i<nums.size();i++){
            int temp=-1,j=i+1,og=i;
            while(j!=og){
                j%=nums.size();
                if(nums[j]>nums[i]){
                    temp=nums[j];
                    break;
                }
                j++;
                j%=nums.size();
            }
            soln.emplace_back(temp);
            
        }
        return soln;
    }
};