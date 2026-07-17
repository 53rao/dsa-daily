class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> soln;
        for(int i=0;i<asteroids.size();i++){
            int destroyed=1,curr=asteroids[i];
            // case 1: curr is -ve and prev is +ve
            if(curr<0&&st.size()&&st.top()>0){
                if(st.size()&&st.top()>0&&abs(curr)<st.top())
                    destroyed=0;
                else{
                    while(st.size()&&st.top()>0&&abs(curr)>abs(st.top())){
                        st.pop();
                    }
                    if(st.size()&&st.top()>0){
                        destroyed=0;

                    }
                }
            }
            // case 2 : curr and prev have same value but oppsiite sign
            if(st.size()&&abs(curr)==abs(st.top())&&curr<0){
                if(st.size()&&curr*-1==st.top()){
                    st.pop();
                    destroyed=0;
                }
            }

            if(destroyed){
                st.push(curr);
            }
        }
         while(st.size()){
            soln.emplace_back(st.top());
            st.pop();
        }
        reverse(soln.begin(),soln.end());
        return soln;
    }
};