class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int k=0;
        for(auto it:mp){
            int temp=it.second;
            for(int i=0;i<temp;i++){
                nums[k++]=it.first;
            }
        }
    }
};