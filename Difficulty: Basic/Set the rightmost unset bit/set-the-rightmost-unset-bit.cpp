class Solution {
  public:
    int setBit(int n) {
        // code here
        string bin="";
        int k=n;
        while(k>=0){
            if(k==1||k==0){
                bin=to_string(k)+bin;
                break;
            }
            else{
                bin=to_string(k%2)+bin;
                k=k/2;
            }
            
        }
        int flag=1,curr=1,soln=0;
        for(int i=bin.size()-1;i>=0;i--){
            if(bin[i]=='1'){
                soln+=curr;
               
            }
            else if(flag){
                flag=0;
                soln+=curr;
            }
            
            
            curr=curr*2;
        }
        if(flag==1){
            soln+=curr;
        }
        return soln;
    }
};