class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=-1,slargest=-1;
        for(int num:arr){
            if(largest==-1){
                largest=num;
            }
            else if(largest<num){
                slargest=largest;
                largest=num;
                
            }
            else if(slargest==-1&&largest!=num){
                slargest=num;
            }
            else if(slargest<num&&num!=largest){
                slargest=num;
            }
        }
        return slargest;
    }
};