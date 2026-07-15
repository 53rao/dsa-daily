class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> soln;
        for(int i=0;i<pow(2,n);i++){
            int j=i,k=n-1;
            vector<int> temp={};
            while(j>0){
                if(j%2){
                    temp.emplace_back(nums[k]);
                }
                j=j>>1;
                k--;
            }
            soln.emplace_back(temp);
        }
        return soln;
    }
};