class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for(char ch:s){
            if(ch=='('||ch=='['||ch=='{'){
                temp.push(ch);
            }
            else{
                if(temp.empty())
                    return false;
                if(ch==')'&&temp.top()=='('){
                    temp.pop();
                }
                else if (ch==']'&&temp.top()=='['){
                    temp.pop();
                }
                else if (ch=='}'&&temp.top()=='{'){
                    temp.pop();
                }
                else
                    return false;
            }
        }
        return temp.size()==0;
    }
};