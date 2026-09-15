class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            map<char,int> temp;
            for(auto it:strs[i])
                temp[it]++;
            mp[temp].emplace_back(strs[i]);
        }
        vector<vector<string>> soln;
        for(auto it:mp){
            soln.emplace_back(it.second);
        }
        return soln;
    }
};