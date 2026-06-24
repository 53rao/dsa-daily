class Solution {
public:

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end()),high=*max_element(bloomDay.begin(),bloomDay.end()),mid,soln=INT_MAX;
        while(low<=high){
            mid=high-(high-low)/2;
            int count=0,curr=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    curr++;
                }
                else{
                    curr=0;
                }
                if(curr==k){
                    count++;
                    curr=0;
                }
            }
            if(count>=m){
                soln=min(mid,soln);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(soln==INT_MAX)
            return -1;
        return soln;
    }
};