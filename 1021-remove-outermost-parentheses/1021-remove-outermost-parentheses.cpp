class Solution {
public:
    string removeOuterParentheses(string s) {
        string soln="";
        int count=0;
        for(int i=0;i<s.size();i++){
            char it=s[i];
            if(it=='('){
                if(count!=0)
                    soln+=it;
                count++;
            }
            else{
                count--;
                if(count!=0){
                    soln+=')';
                }
            }
        }
        return soln;
    }
};