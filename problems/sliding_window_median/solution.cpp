//function next() and prev() is used to get the solution

//multiset is used to store elements of window size k
//pointer mid is always pointing to mid, 
//when adding a new element, check if its smaller than mid or not, if yes then decreament mid
//when removing an element, check if its smaller than mid, then increament pointer

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> s;
        for(int i = 0; i< k; ++i){ s.insert(nums[i]); }
        auto mid = next(s.begin(), k/2);
        ans.push_back((double(*mid) + double(*(prev(mid, 1-k%2))))/2);
        // in case of odd : ( mid + mid )/2 = mid
        // in case of even : (mid + prev )/2 = median


        int i = k; 
        while(i < nums.size()){ 
            s.insert(nums[i]);
            // update mid pointer
            if(nums[i] < *mid) mid--;
            if(nums[i-k]<= *mid) mid++;

            s.erase(s.find(nums[i-k]));    // find returns iterator at that value, erase deletes value at that iterator
            ans.push_back((double(*mid) + double(*(prev(mid, 1-k%2))))/2);
            i++;
        }
        return ans;
    }
};



// ------------------------------------------------------------------------------------

// Idea from data stream in median ques: https://leetcode.com/problems/find-median-from-data-stream/description/
/*
class Solution {
public:
    
    #define pb push_back
    #define ff first
    #define ss second
    
    
    //initialising...
    priority_queue<int>pq;//max_heap
    priority_queue<int,vector<int>,greater<int>>pq2;//min heap
    vector<double>ans;
    
    //balancing
    void balance(){
        if(pq.size()>(pq2.size()+1)){
            pq2.push(pq.top());
            pq.pop();
        }
        if(pq2.size()>(pq.size()+1)){
            pq.push(pq2.top());
            pq2.pop();
        }
    }
    
    //adding new val
    void add(int val){
        if((pq.empty()&&pq2.empty())||val<pq.top()){
            pq.push(val);
        }else pq2.push(val);
    }
    
    //adding median to our answer!
    void updateAns(){
        if(pq.size()==pq2.size()){
            double one=pq.top();
            one+=pq2.top();
            ans.pb(one/2);
        }
        else ans.pb((pq.size()>pq2.size())?pq.top():pq2.top());
    }
    
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        for(int i=0;i<k;i++){
            add(a[i]);
            balance();
        }
        updateAns();
        for(int i=k;i<n;i++){
            //removing prev val
            int prev=a[i-k],indx=0;
            vector<int>temp;
            if(!pq.empty()&&prev<=pq.top()){
                while(prev!=pq.top()){
                    temp.pb(pq.top());
                    pq.pop();
                }
                pq.pop();
                int l=temp.size();
                while(indx<l){pq.push(temp[indx++]);}
            }else if(!pq2.empty()){
                while(prev!=(pq2.top())){
                    temp.pb(pq2.top());
                    pq2.pop();
                }
                pq2.pop();
                int l=temp.size();
                while(indx<l){pq2.push(temp[indx++]);}
            }
            add(a[i]);
            balance();
            updateAns();
        }
        return ans;
    }
};
*/