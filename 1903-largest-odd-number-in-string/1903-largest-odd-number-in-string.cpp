class Solution {
public:
    string largestOddNumber(string num) {
        int high=num.size()-1;
        while(0<=high){
            if((num[high]-'0')%2!=0){
                return num.substr(0,high+1);
            }
            high--;
        }
        return "";
    }
};