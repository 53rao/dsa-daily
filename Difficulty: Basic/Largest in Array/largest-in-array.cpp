class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int soln=arr[0];
        for(int i=1;i<arr.size();i++){
            if(soln<arr[i]){
                soln=arr[i];
            }
        }
        return soln;
    }
};
