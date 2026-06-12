class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0,j=0,prev;
        vector<int> soln;
        
        if(a[i]==b[j]){
            
            soln.emplace_back(b[j]);
            prev=b[j];
            j++;
            i++;
            
        }
        else if(a[i]>b[j]){
            soln.emplace_back(b[j]);
            prev=b[j];
            j++;
        }
        else{
            soln.emplace_back(a[i]);
            prev=a[i];
            i++;
        }
        
        while(i<a.size()&&j<b.size()){
            if(a[i]<=prev){
                while(a[i]<=prev){
                    i++;
                }
            }
            else if(b[j]<=prev){
                while(b[j]<=prev){
                    j++;
                }
            }
            else if(a[i]==b[j]){
                soln.emplace_back(b[j]);
                prev=b[j];
                j++;
                i++;
            }
            else if(a[i]>b[j]){
                soln.emplace_back(b[j]);
                prev=b[j];
                j++;
            }
            
            else{
                soln.emplace_back(a[i]);
                prev=a[i];
                i++;
            }
        }
        while(i<a.size()){
            if(a[i]<=prev){
                while(a[i]<=prev){
                    i++;
                }
            }
            else{
            soln.emplace_back(a[i]);
                prev=a[i];
                i++;
            }
        }
        while(j<b.size()){
            if(b[j]<=prev){
                while(b[j]<=prev){
                    j++;
                }
            }
            else{
            soln.emplace_back(b[j]);
                prev=b[j];
                j++;
            }
        }
        return soln;
        
    }
};