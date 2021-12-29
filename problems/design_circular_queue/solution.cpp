class MyCircularQueue {
public:
    
    int head, tail, cur_size, max_size;
    vector<int> q;
    
    MyCircularQueue(int k) {
        q.resize(k);
        for(int i = 0;i<k;i++){
            q[i] = 0;
        }
        head = 0;
        tail = 0;
        max_size = k;
        cur_size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[tail] = value;
        tail = (tail + 1) % max_size;
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        q[head] = 0;
        head = (head + 1) % max_size;              
        cur_size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : tail == 0 ? q[max_size-1]: q[tail-1];
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == max_size;
    }
};



