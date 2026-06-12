class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> soln(n,0);
        for(int i=0;i<nums.size();i++){
            soln[(i+k)%n]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=soln[i];
        }
    }
};