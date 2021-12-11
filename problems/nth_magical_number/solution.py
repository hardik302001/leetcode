'''

https://leetcode.com/problems/nth-magical-number/discuss/154687/Python-using-gcd-and-lcm-no-search-needed

'''


class Solution(object):
	def lcm(self, x, y):
		return x*y//gcd(x,y)

	def nthMagicalNumber(self, N, A, B):
		lcmAB = self.lcm(A,B)
		seq = set()
		for i in range(1, lcmAB//A+1):
			seq.add(i*A)
		for i in range(1, lcmAB//B+1):
			seq.add(i*B)
		cand = sorted(seq)
		ans = ((N-1)//len(cand))*lcmAB + cand[N%len(cand)-1]
		return ans % (10**9+7)