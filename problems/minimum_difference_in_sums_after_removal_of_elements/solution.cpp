class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long long ans = 100000000000000;
        priority_queue<int>map;
        priority_queue<int , vector<int> , greater<int> > mip;
        int n = nums.size()/3;
        
        vector<long long >ma(3*n, 0);
        long long s = 0;
        for(int i = 0;i<3*n;i++){
            map.push(nums[i]);
            s = s + nums[i];
            if (map.size()>n){
                int topa = map.top();
                s = s- topa;
                map.pop();
                
            }
            
            ma[i] = s;
            // cout<<ma[i]<<endl;
        }
        
        vector<long long>mi(3*n, 0);
        s = 0;
        for(int i = 3*n-1;i>=0;i--){
            mip.push(nums[i]);
            s = s + nums[i];
            if (mip.size()>n){
                int topa = mip.top();
                s = s- topa;
                mip.pop();
                
            }
            
            mi[i] = s;
            // cout<<mi[i]<<endl;
        }
//         for(int i = 0;i<3*n;i++){
//             cout<<ma[i]<<" ";
//         }
//         cout<<endl;
        
//         for(int i = 0;i<3*n;i++){
//             cout<<mi[i]<<" ";
//         }
//         cout<<endl;
        
        for(int i = n-1;i<2*n;i++){
            long long  res = ma[i] - mi[i+1];
            // cout<<res<<endl;
            ans = min(ans , (ma[i] - mi[i+1]));
        }
        return ans;
        
        
        
    }
    
    long long min(long long a, long long b){
        return (a<b)?a:b;
    }
};