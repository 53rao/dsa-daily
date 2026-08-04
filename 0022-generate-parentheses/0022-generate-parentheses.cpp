class Solution {
public:
    void adder(int n,string &curr,int open,int close,vector<string> &soln){
        if(curr.size()==n*2){
            soln.emplace_back(curr);
            return;
        }
        if(open<n){
            curr+='(';
            adder(n,curr,open+1,close,soln);
            curr.pop_back();
        }
        if(close<open){
            curr+=')';
            adder(n,curr,open,close+1,soln);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> soln;
        string curr="";
        adder(n,curr,0,0,soln);
        return soln;
    }
};