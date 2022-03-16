class Solution:
    def numWays(self, s: str) -> int:
        n,ones = len(s),[]
        for i,val in enumerate(s):
            if val == '1':
                ones.append(i)
        total = len(ones)
        if total == 0:
		    # ref: https://en.wikipedia.org/wiki/Combination
			# combination of selecting 2 places to split the string out of n-1 places
            return ((n-1)*(n-2)//2) % (10**9+7) 
        if total % 3 != 0:
            return 0
        target = total // 3
        return (ones[target]-ones[target-1])*(ones[target*2]-ones[target*2-1])%(10**9+7)