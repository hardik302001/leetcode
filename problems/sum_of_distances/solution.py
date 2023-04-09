class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        d = defaultdict(list)
        for i , v in enumerate(nums):
            d[v].append(i)
        ans = [-1]*(len(nums))
        def solve(l):
            n = len(l)
            ltr = [0]*n
            rtl = [0]*n

            for i in range(1, n):
                ltr[i] = ltr[i-1] + i*(l[i] - l[i-1])

            cnt = 1;
            for i in range(n-2, -1, -1):
                rtl[i] = rtl[i+1] + (cnt * (l[i+1] - l[i]))
                cnt+=1


            for i in range(n):
                r = ltr[i] + rtl[i]
                ans[l[i]] = r
	
        for i in d:
            if len(d[i])==1:
                ans[d[i][0]] = 0
                continue
            solve(d[i])
        
        return ans