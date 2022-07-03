
class MyStack {
public:
    
    queue<int>que;
    MyStack() {
        
    }
    
    void push(int x) {    //every time we push into queue, we do a cycle, and get the lastest element at front
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}
    
    int pop() {
        int ans = top();
        que.pop();
        return ans;
    }
    
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
    
    
};



