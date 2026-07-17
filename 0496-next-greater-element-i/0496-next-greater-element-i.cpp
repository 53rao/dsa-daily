class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        vector<int> soln;
        for(int i=0;i<nums1.size();i++){
            int j;
            for(j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    mp[nums1[i]]=j;
                    break;
                }
            }
            int temp=-1;
            j++;
            while(j<nums2.size()){
                if(nums2[j]>nums1[i]){
                    temp=nums2[j];
                    break;
                }
                j++;
            }
            soln.emplace_back(temp);
        }
        return soln;
    }
};