class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int i=0,j=0,prev=-1;
        vector<int> soln;
        while(i<arr1.size()&&j<arr2.size()){
            if((arr1[i]==arr2[j])&&(prev==-1||arr1[i]>prev)){
                soln.emplace_back(arr1[i]);
                prev=arr1[i];
                i++;
                j++;
            }
            else if(arr2[j]>arr1[i]){
                i++;
            }
            else{
                j++;
            }
        }
        return soln;
    }
};