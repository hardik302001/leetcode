#monotonic function
#binary serach O(nlogn)
#more the maximum value of product considered, less the number of stores required
#so monotonic, we can apply bs..

#EXACTLY SAME AS :  https://leetcode.com/problems/koko-eating-bananas/submissions/
# also see: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
# also see: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/
# also see: https://leetcode.com/problems/heaters/                    
# very important \U0001f446

'''
# minimise maximum, so we return do hi = mid for valid case, and return low

# if it was maximise minimum, then we will do li = mid +1 for valid case and return li - 1
# keep something extra in r...bcz (l<r) and we are returning l-1, so we wont chcek ever on r, so keep extra
#                        OR
# keep a speerate variable ans , and equate ans to the value, whenever we get valid result for answer from function
# see: https://leetcode.com/problems/maximum-running-time-of-n-computers/submissions/
'''


class Solution:
    def minimizedMaximum(self, n: int, quan: List[int]) -> int:
        lo,hi = max(1,sum(quan)//n) , max(quan)         #low when all elements equal (or) 1     #high can be atmax max(quan) bcz we need to minimise maximum
        while lo < hi:
            mid = (lo + hi) // 2
            if self.canTakeProd(mid, quan, n):
                hi = mid
            else:
                lo = mid + 1
        return lo
    
    
    
    def canTakeProd(self,k, quan, n):                         #if we can take all products
        store = 0
        for i in range(len(quan)):
            store += int(math.ceil(quan[i]/int(k)))    #to conisder how many stores will quan[i] take, if we can have atmost k products in each store
            
        return store <= n 
            
            
            
#             if store > n: return False       # k is too small, less k leads to more number of stores   
#         return True   #bcz some stores can be 0!
    
    
    
      


'''

very important ques
also see: https://www.lintcode.com/problem/848/description


class Solution {
public:
    double minmaxGasDist(vector<int> &s, int k) {
        // Write your code here
        double l = 0;
        double r = s.back() - s[0];
        double ans = r;
        while(l + 0.000001 < r){
            double m =  l + (r-l)/2.0;
            //cout<<m<<endl;
            if(check(m , s, k)){
                r = m;
            }
            else{
                l = m;
            }
        }

        return l;
    }

    bool check(double m , vector<int>&s , int k){
        int c = 0;  // total number of gas station needed to have max distance as m
        for(int i = 1;i<s.size();i++){
            double diff = s[i]-s[i-1];
            c = c + ceil(diff/m)-1;  // ceil will give divide diff as some alpha m and 1 piece of distance less than m, so still we have our maximum distance as m
            // we did ceil - 1, bcz we dont need count of parts of disatnce , we need actual station, so that will be ceil - 1;
            // draw on notebook , you can see yourself!

        }
        if(c>k){
            return false;  // bcz we need c stations to keep maximum distance as m, but we are allowed only k, so some part of stance will be more than m , thus we wont have maximum as m
        }
        else{
            return true;
        }
        
    }
};


'''