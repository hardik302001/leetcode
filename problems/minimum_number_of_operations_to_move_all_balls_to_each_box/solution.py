'''
# O(n^2)

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ind = []
        for i in range(n):
            if boxes[i]=='1':
                ind.append(i)
        ans = []
        
        for i in range(n):
            s = 0
            for x in ind:
                s += abs(i-x)
            ans.append(s)
        return ans
'''
    
# https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/1075595/Java%3A-O(n)-left-sum-and-right-sum
# O(n)
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ans = [0]*n
        l = [0]*(n)
        r = [0]*(n)
        
        c = int(boxes[0])
        for i in range(1, n):
            l[i] = l[i-1]+c
            if boxes[i]=='1':
                c +=1
            
            
        c = int(boxes[n-1])
        for i in range(n-2, - 1, -1):
            r[i] = r[i+1] + c
            if boxes[i]=='1':
                c+=1
                    
      
        
        for i in range(n):
            ans[i] = l[i]+r[i]
        return ans

    
    # even if you want O(1) space: do it
    # https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/discuss/1075518/Clean-Python-3-two-passes-O(N)
    
    