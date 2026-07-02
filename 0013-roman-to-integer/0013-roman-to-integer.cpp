class Solution {
public:
    int romanToInt(string s) {
        map<char,int> dict;
        dict['I']=1;
        dict['V']=5;
        dict['X']=10;
        dict['L']=50;
        dict['C']=100;
        dict['D']=500;
        dict['M']=1000;
        int n=s.size()-1,prev=dict[s[n--]],curr,soln=prev;
        while(n>=0){
            curr=dict[s[n--]];
            if(prev<=curr){
                soln+=curr;
            }
            else{
                soln-=curr;
            }
            prev=curr;
        }
        return soln;
    }
};