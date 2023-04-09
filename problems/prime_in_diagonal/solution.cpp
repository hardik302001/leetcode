
bool isprime(int v) {
	for(int i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
		int ma=0;
		int N=nums.size();
		int x;
		for(int x = 0;x<N;x++) if(isprime(nums[x][x])) ma=max(ma,nums[x][x]);
		for(int x = 0;x<N;x++) if(isprime(nums[x][N-1-x])) ma=max(ma,nums[x][N-1-x]);
        return ma;
    }
};
