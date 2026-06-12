class Solution {
  public:
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int low=0,high=arr.size()-1,mid;
        while(low<=high){
            mid=high-(high-low)/2;
            if(arr[mid]==k)
                return true;
            else if(arr[mid]<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};