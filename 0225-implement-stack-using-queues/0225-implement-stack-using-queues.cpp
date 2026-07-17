
class MyStack {
public:
    queue<int> local;
    MyStack() {
        
    }
    
    void push(int x) {
        local.push(x);
    }
    
    int pop() {
        queue<int> temp;
        int val=-1;
        while(local.size()){
            if(local.size()==1){
                val=local.front();
                local=temp;
                return val;
                
            }
            else{
                temp.push(local.front());
                local.pop();
            }
        }
        return val;
    }
    
    int top() {
        return local.back();
    }
    
    bool empty() {
        return local.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */