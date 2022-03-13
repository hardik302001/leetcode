class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n =len(nums)
        d = []
        
        for i in range(n):
            if nums[i]==key:
                d.append(i)
        s = set()
        for i in d:
            p = max(0 , i-k)
            q = min(n-1 , i+k)
            
            dd = []
            for i in range(p , q+1):
                s.add(i)
            # ans.extend(dd)
            
        ans = list(s)
        ans.sort()
        return ans
                