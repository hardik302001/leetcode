class Solution:
    def minOperations(self, logs: List[str]) -> int:
        c = 0
        for i in logs:
            if i[0]=='.':
                if i[1]=='/':
                    c = c + 0
                else:
                    if c>0:
                        c = c -1
            else:
                 c = c  + 1
        return c