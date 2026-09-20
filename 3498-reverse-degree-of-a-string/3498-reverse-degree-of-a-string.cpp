class Solution {
public:
    int reverseDegree(string s) {
        int soln=0;
        for(int i=0;i<s.size();i++){
            soln=soln+(i+1)*('a'-s[i]+26);
        }
        return soln;
    }
};