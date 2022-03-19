class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<long double>pq;
        double s = 0;
        for(auto it: nums){
            pq.push(it);
            s+=it;
        }
        
        
        long double need = s/(long double)2;
        // cout<<need<<e/ndl;
        
        int c= 0;
        while(need>0){
            long double t = pq.top();
            // cout<<t<<endl;
            pq.pop();
            need-= t/(long double)2;
            // cout<<"half" << t/double(2)<<endl;
            pq.push(t/(long double)2);
            c+=1;
        }
                

        return c;
    }
};