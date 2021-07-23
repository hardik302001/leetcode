class Solution:
    def findLHS(self, nums: List[int]) -> int:
        
        counts = collections.Counter(nums)
        
        score = 0
        
        for i in nums:
            a, b, c = counts[i+1], counts[i], counts[i-1]            
            score = max(
                score,
                a+b if a and b else 0,
                b+c if b and c else 0
            )
            
        return score             