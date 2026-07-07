class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        int k=n;
        while(k){
            if(k%2!=0&&k!=1)
                return false;
            k=k/2;
        }
        return true;
    }
};