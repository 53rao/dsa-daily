class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int temp=arr[mid]-mid-1;
            if(temp<k){
                    low=mid+1;
            }
            else{
                high=mid-1; 
            }
        }
        if(high<0){
            int soln=arr[low];
            int temp=arr[low]-low-1;
            while(temp>=k){
                temp--;
                soln--;
            }
            return soln;
        }
        else{
            int soln=arr[high];
            int temp=arr[high]-high-1;
            while(temp<k){
                temp++;
                soln++;
            }
            return soln;
        }
       
        return -1;
    }
};