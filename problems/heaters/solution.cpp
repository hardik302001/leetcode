class Solution {
public:

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // first we will sort the house vector and the heaters vector.
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int l,mid,r;
        l=0;
        r=1000000005; 
        while(l<r)
        {
           mid=l+(r-l)/2;
            // cout<<mid<<endl;
            if(check(mid,houses,heaters))
            {
             r=mid;
            }
            else
            {
            l=mid+1;
            }
        }
        return l;
    }
        // This is the check function here if the current mid value satsisfies the answer we will return true else          we will return false;

    bool check(int mid,vector<int>& houses, vector<int>& heaters){
      int  n=heaters.size();
        for(auto h:houses )
        {
             auto m=lower_bound(heaters.begin(),heaters.end(),h-mid)-heaters.begin(); 
			 //Here we will check that if the current house has some heater in the range between  h-mid && h+mid;
			 // if there is no heater in that range we will return false
            if(m==n)
            {
            return false;
            }
         
            if(heaters[m]>h+mid)
            {
                return false;
            }
                                     
        }
        return true;
    }
};