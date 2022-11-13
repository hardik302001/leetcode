class Solution {
	public:
		int subarrayLCM(vector<int>& nums, int k) {
			int n = nums.size();
			long long ans = 0;
			for(int i = 0; i < n; i++)
			{
				// LCM * GCD = Product of nums
				// LCM = Product of nums/GCD
				long long int p = 1; 
				int lcm = 1;
				for(int j = i; j < n; j++)
				{
					p *= nums[j];
					lcm = p/__gcd(lcm,nums[j]);
					if(lcm == k)
					{
						ans++;
					}
					p = lcm;
				}
			}
			return ans;
		}
	};






// --------------------------------------------------------
/*
class Solution {
public:
	int subarrayLCM(vector<int>& a, int k) {
		int n = a.size(), ans = 0;
		
        for(int i = 0; i < n; i++) {
			long long l = 1;
            
			for(int j = i; j < n; j++) {
				l = lcm(l, a[j]);
				if(l == k) ans++;
				else if(l > k) break;
			}
		}
        
		return ans;
	}
};

*/