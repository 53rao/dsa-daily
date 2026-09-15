class Solution {
public:
    void backtrack(vector<string> &soln,int n,int open,int close,string curr){
        if(open+close==2*n){
            soln.emplace_back(curr);
            return;
        }
        if(open<n){
            string temp=curr+'(';

            backtrack(soln,n,open+1,close,temp);
        }
        if(open>close&&open<=n){
            string temp=curr+')';
    
            backtrack(soln,n,open,close+1,temp);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        string curr="(";
        backtrack(soln,n,1,0,curr);
        return soln;
    }
};