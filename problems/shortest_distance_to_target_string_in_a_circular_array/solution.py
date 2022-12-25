class Solution:
    def closetTarget(self, words: List[str], target: str, s: int) -> int:
        n = len(words)
        ind = n+s
        
        ans = 10000000
        words = words + words + words

        for i in range(len(words)):
            if words[i]==target:
                ans = min(ans, abs(i-ind))
                
        
        if ans==10000000:
            return -1
        else:
            return ans