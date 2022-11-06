 long long v1, v2,ind1, ind2;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>>>p1;
        priority_queue<pair<int, int> , vector<pair<int , int>> , greater<pair<int, int>>>p2;

        int val = -1;
        int n = costs.size();
        int l = 0;
        int r  = n-1;
        long long s = 0;
        for(int i = 0;i<min(c, n); i++){
            p1.push({costs[i], i});
            l++;
            val++;
        }
        

        for(int i  = n-1;i>=max(l , n-c);i--){
            p2.push({costs[i], i});
            r--;
            val--;
        }
        
        int x = 0;
               
        while(k>0){
            bool f1 = false;
            bool f2 = false;
            if(p1.size()){
                v1 = p1.top().first;
                ind1 = p1.top().second;
            }   
            else {
                f1 = true;
                v1 = 10000000000000;
                ind1 = 1000000000000;
            }
            
            if(p2.size()){
                v2 = p2.top().first;
                ind2 = p2.top().second;
            }  
            else {
                f2 = true;
                v2 = 1000000000000;
                ind2 = 1000000000000;
            }
            x++;
            if(v1<v2){
                s+=v1;
                p1.pop();
                if(r>=l){
                    p1.push({costs[l], l});
                    l++;
                }
            }
            else if(v1>v2){
                s+=v2;
                p2.pop();
                if(r>=l){
                    p2.push({costs[r], r});
                    r--;
                }
            }else{
                if(ind1>ind2){
                    s+=v2;
                    p2.pop();
                    if(r>=l){
                        p2.push({costs[r], r});
                        r--;
                    }
                }else{
                    s+=v1;
                    p1.pop();
                    if(r>=l){
                        p1.push({costs[l], l});
                        l++;
                    }   
                }
            }
            if(f1 and f2) x++;
            k--;
        }     
        
    
        
        return s;
    }
};