class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        string soln="";
        while(strs[0][i]){
            char ch=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size()||strs[j][i]!=ch)
                    return soln;
            }
            soln+=ch;
            i++;
        }
        return soln;
    }
};