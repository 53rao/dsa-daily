class Solution {
public:
    int maxDepth(string s) {
        int soln=0,count=0;
        for(char it:s){
            if(it=='('){
                count++;
                soln=max(soln,count);
            }
            else if(it==')'){
                count--;
            }
        }
        return soln;
    }
};