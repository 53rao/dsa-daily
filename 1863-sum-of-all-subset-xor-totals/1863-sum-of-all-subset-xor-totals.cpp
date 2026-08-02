class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int soln=0;
        int n=nums.size();
        for(int i=0;i<pow(2,n);i++){
            int curr=0,j=i,k=n-1;
            while(j>0){
                if(j%2)
                    curr=curr^nums[k];
                k--;
                j=j>>1;
            }
            soln+=curr;
        }
        return soln;
    }
};