class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0,bottom=matrix.size()-1,left,right,midv,midh;
        while(top<=bottom){
            left=0;
            right=matrix[0].size()-1;
            midv=bottom-(bottom-top)/2;
            if(matrix[midv][left]<=target&&target<=matrix[midv][right]){
                while(left<=right){
                    midh=right-(right-left)/2;
                    if(matrix[midv][midh]==target)
                        return true;
                    else if(matrix[midv][midh]<target){
                        left=midh+1;
                    }
                    else{
                        right=midh-1;
                    }
                }
                return false;
            }
            else if(target<matrix[midv][left]){
                bottom=midv-1;
            }
            else{
                top=midv+1;
            }
        }
        return false;
    }
};