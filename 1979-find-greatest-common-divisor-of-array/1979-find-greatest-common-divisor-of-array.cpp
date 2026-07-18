class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minele=*min_element(nums.begin(),nums.end());
        int maxele=*max_element(nums.begin(),nums.end());
        int soln=minele;
        while(soln>1){
            if(minele%soln==0&&maxele%soln==0)
                return soln;
            soln--;
        }
        return soln;
    }
};