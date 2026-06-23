class Solution {
public:
  
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end()),mid,soln=high;
        while(low<=high){
            mid=high-(high-low)/2;
            int time=0;
            for(int i=0;i<piles.size();i++){
                time+=(piles[i]+mid-1)/mid;
            }
            if(time<=h){
                high=mid-1;
                soln=min(soln,mid);
            }
            else
                low=mid+1;
        }
        return soln;
    }
};