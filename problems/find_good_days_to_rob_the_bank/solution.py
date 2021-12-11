class Solution:
    def goodDaysToRobBank(self, security: List[int], time: int) -> List[int]:
        n = len(security)
        
        left = [0 for _ in range(n)]
        right = [0 for _ in range(n)]
        
        for i in range(1, n):
            if security[i] <= security[i - 1]:
                left[i] += left[i - 1] + 1
            else: 
                left[i] = 0 
        
        for i in range(n - 2, -1, -1):
            if security[i] <= security[i + 1]:
                right[i] += right[i + 1] + 1
            else: 
                right[i] = 0 
        
        ans = []
        for i in range(time, n - time):
            if left[i] >= time and right[i] >= time:
                ans.append(i)
                
        return ans