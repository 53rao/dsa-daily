class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        for(int i=0;i<s.size();i++){
            if(s==goal)
                return true;
            char temp=s[0];
            s=s.substr(1,s.size()-1)+temp;
        }
        return false;
    }
};