class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
        int k=image[sr][sc];
        if(k==color)
            return image;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        vector<vector<int>> soln;
        q.push({sr,sc});
        while(q.size()){
            int len=q.size();
            for(int i=0;i<len;i++){
                int x=(q.front()).first;
                int y=(q.front()).second;
                q.pop();
                if(x>0){
                    if(image[x-1][y]==k){
                        q.push({x-1,y});
                        image[x-1][y]=color;
                    }
                }
                if(y>0){
                    if(image[x][y-1]==k){
                        q.push({x,y-1});
                        image[x][y-1]=color;
                    }
                }
                if(x+1<image.size()){
                    if(image[x+1][y]==k){
                        q.push({x+1,y});
                        image[x+1][y]=color;
                    }
                }
                if(y+1<image[0].size()){
                    if(image[x][y+1]==k){
                        q.push({x,y+1});
                        image[x][y+1]=color;
                    }
                }
            }
        }
        return image;
    }
};