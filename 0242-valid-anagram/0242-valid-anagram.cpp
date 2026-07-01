class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> s1;
        map<char,int> t1;
        if(s.size()!=t.size())
            return false;
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
            t1[t[i]]++;
        }
        return t1==s1;
    }
};