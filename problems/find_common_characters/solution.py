class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        result = []
        for c in set(A[0]):
            count = A[0].count(c)
            occurences = 1
            for i in range(1,len(A)):
                if c in A[i]:
                    count = min(count,A[i].count(c))
                    occurences += 1
                else:
                    break
            if occurences == len(A):
                for i in range(count):
                    result.append(c)
                    
        return result