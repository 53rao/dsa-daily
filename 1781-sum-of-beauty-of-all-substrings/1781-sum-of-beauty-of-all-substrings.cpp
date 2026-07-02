class Solution {
public:
    int beautySum(string s) {
        int soln=0;
        for(int i=0;i<s.size();i++){
            map<char,int> count;
            for(int j=i;j<s.size();j++){
                count[s[j]]++;
                int mini=INT_MAX,maxi=0;
                for(auto it:count){
                    if(it.second>0){
                        mini=min(it.second,mini);
                        maxi=max(maxi,it.second);
                    }
                }
                soln+=maxi-mini;
            } 
        }
        return soln;
    }
};