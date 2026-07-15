class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        
        while(start&&goal){
            count+=start%2^goal%2;
            start=start>>1;
            goal=goal>>1;
        }
        while(start>0){
            if(start%2!=0)
                count++;
            start=start>>1;
        }
        while(goal>0){
            if(goal%2!=0)
                count++;
            goal=goal>>1;
            
        }
        return count;
    }
};