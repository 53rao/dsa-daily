class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=accumulate(weights.begin(),weights.end(),0),soln=high,mid;
        while(low<=high){
            mid=high-(high-low)/2;
            int count=1,sum=0;
            for(int i=0;i<weights.size();i++){
                if(sum+weights[i]>mid){
                    count++;
                    sum=weights[i];
                }
                else{
                    sum+=weights[i];
                }
            }   
            
            if(count<=days){
                soln=min(soln,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return soln;
    }
};