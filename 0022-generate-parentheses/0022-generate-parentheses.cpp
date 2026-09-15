class Solution {
public:
    void backtrack(vector<string> &soln,int n,int open,int close,string curr){
        if(open+close==2*n){
            soln.emplace_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            backtrack(soln,n,open+1,close,curr);
            curr.pop_back();
        }
        if(open>close&&open<=n){
            curr.push_back(')');
            backtrack(soln,n,open,close+1,curr);
            curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        string curr="(";
        backtrack(soln,n,1,0,curr);
        return soln;
    }
};