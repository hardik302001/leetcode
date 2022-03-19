/*
// TC: O(logn) for push and pop
// SC: O(n)

class FreqStack {
    priority_queue<pair<int, pair<int, int>>> q;
    unordered_map<int, int> freq;
    int pos = 0;
public:
    void push(int x) {
        q.emplace(++freq[x], make_pair(++pos, x));
    }
    
    int pop() {
        auto val = q.top();
        q.pop();
        int x = val.second.second;
        freq[x]--;
        return x;
    }
};
*/


// https://leetcode.com/problems/maximum-frequency-stack/discuss/1086635/C%2B%2B-or-Hash-map-%2B-Stack-or-O(1)-Beats-100-or-Explanation
// TC: O(1) for push and pop
// SC: O(n)

class FreqStack {
public:
    int max_frequency; // keep note of the current maximum frequency
    unordered_map<int, int> freq_mp; // to store the freq of numbers
    unordered_map<int, stack<int>> freq_stack_mp; // to store the numbers with same freq in a stack
    
    FreqStack() {
        // initially maximum frequency is 0
        max_frequency=0;
    }
    
    void push(int x) {
        // increase the freq of x in frequency map
        ++freq_mp[x];
        
        // update max_frequency
        if(max_frequency<freq_mp[x]) max_frequency = freq_mp[x];
        
        // push x to its freq stack
        freq_stack_mp[freq_mp[x]].push(x);
    }
    
    int pop() {
        // get the top element from the stack of maximum frequency
        // here stack is used for taking care of the "frequency tie" condition
        int curr_top = freq_stack_mp[max_frequency].top();
        
        // update both the maps
        freq_stack_mp[max_frequency].pop();
        --freq_mp[curr_top];
        
        // if the stack of maximum element becomes empty, then delete it from "freq_stack_mp" along with decreasing "max_frequency"
        if(freq_stack_mp[max_frequency].empty()) {
            freq_stack_mp.erase(max_frequency);
            --max_frequency;
        }
        
        // return the current top element
        return curr_top;
    }
};