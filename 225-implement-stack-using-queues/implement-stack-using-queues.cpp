class MyStack {
public:
    queue<int> q1,q2;
    bool f;
    MyStack() {
        f=0;
    }
    
    void push(int x) {
        if(f){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());q2.pop();
            }
            f=!f;
        }
        else{
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());q1.pop();
            }
            f=!f;
        }
    }
    
    int pop() {
        if(f){
            int x=q2.front();q2.pop();
            return x;
        }
        else{
            int x=q1.front();q1.pop(); 
            return x;
        }
    }
    
    int top() {
        if(f){
            return q2.front();
        }
        else{
            return q1.front(); 
        }
    }
    
    bool empty() {
        if(f){
            return q2.empty();
        }
        else {
            return q1.empty();        
        }
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