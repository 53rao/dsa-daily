class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix;
        prefix.emplace_back(0);
        int curr=0,soln=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            prefix.emplace_back(curr);
        }
        for(int i=0;i<prefix.size();i++){
            for(int j=i+1;j<prefix.size();j++){
                if(prefix[j]-prefix[i]==k)
                    soln++;
            }
        }
        return soln;
    }
};