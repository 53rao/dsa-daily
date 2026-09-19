class Solution {
public:
    
    void comb(string &digits,int &n,map<char,vector<char>> &mp,vector<string> &soln,int idx,string curr){
        if(idx==n){
            soln.emplace_back(curr);
            return;

        }
        for(int i=0;i<mp[digits[idx]].size();i++){
            string temp=curr+mp[digits[idx]][i];
            comb(digits,n,mp,soln,idx+1,temp);
        }

    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        int n=digits.size();
        vector<string> soln;
        string curr="";
        comb(digits,n,mp,soln,0,curr);
        return soln;
    }
};