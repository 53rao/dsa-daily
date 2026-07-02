class Solution {
public:
    
    string longestPalindrome(string s) {
        string soln="",curr;
        int low,high;
        for(int i=0;i<s.size();i++){
            low=i,high=i;
            while(low>=0&&high<s.size()){
                if(s[low]!=s[high])
                    break;
                curr=s.substr(low,high-low+1);
                if(curr.size()>soln.size()){
                    soln=curr;
                }
                low--;
                high++;
            }
            
            low=i,high=i+1;
            while(low>=0&&high<s.size()){
                if(s[low]!=s[high])
                    break;
                curr=s.substr(low,high-low+1);
                if(curr.size()>soln.size())
                    soln=curr;
                low--;
                high++;
            } 
        }
        return soln;
    }
};