class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int low=0,high=arr.size()-1,mid,soln=-1;
        while(low<=high){
            mid=high-(high-low)/2;
            if(arr[mid]<=x){
                soln=max(soln,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
                
        }
        return soln;
    }
};
