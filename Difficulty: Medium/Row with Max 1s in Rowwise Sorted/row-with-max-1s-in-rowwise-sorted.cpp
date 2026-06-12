class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int soln=-1,curr,maxcount=-1;
        for(int i=0;i<arr.size();i++){
            curr=0;
            for(int j=0;j<arr[0].size();j++){
                if(arr[i][j]==1)
                    curr++;
            }
            if(curr!=0&&curr>maxcount){
                maxcount=curr;
                soln=i;
            }                
        }
        return soln;
    }
};