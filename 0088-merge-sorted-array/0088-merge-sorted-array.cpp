class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,curr=0;
        vector<int> soln(m+n);
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                soln[curr]=nums1[i];
                i++;
            }
            else{
                soln[curr]=nums2[j];
                j++;
            }
            curr++;
        }
        while(i<m){
            soln[curr]=nums1[i];
            curr++;
            i++;
        }
        while(j<n){
            soln[curr]=nums2[j];
            curr++;
            j++;
        }
        nums1=soln;
    }
};