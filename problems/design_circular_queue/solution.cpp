class MyCircularQueue {
public:
    MyCircularQueue(int k) : head(0), tail(0), capacity(k), size(0), q(vector<int>(k, -1)) {}
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[tail++] = value;
        tail %= capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        q[head++] = -1;
        head %= capacity;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[head];
    }
    
    int Rear() { // tail = 0, means queue is full, so we return cap-1, else we do tail-1
        // why index -1? bcz we are moving one step ahead after enqueue operation! 
        return isEmpty() ? -1 : tail == 0 ? q[capacity-1]: q[tail-1];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
private:
    int head, tail, size, capacity;
    vector<int> q;
};