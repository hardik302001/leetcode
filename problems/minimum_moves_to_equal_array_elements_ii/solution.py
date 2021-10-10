class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        def minOperations(l, k):
            
            l.sort()
            p = l.copy()
            # print(l)
            sz = len(l)

            mid = l[sz//2]
            ans1 = 0
            for i in range(sz):
                if l[i]<mid:
                    c = (mid-l[i])//k
                    ans1 = ans1 + c
                    l[i] = l[i] + c*k
                elif l[i]>mid:
                    c = (l[i]-mid)//k
                    ans1 = ans1 +c
                    l[i] = l[i]-c*k

            return ans1
        
        return minOperations(nums,1)