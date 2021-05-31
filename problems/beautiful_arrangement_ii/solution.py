#zigzag pattern
'''
https://leetcode.com/problems/beautiful-arrangement-ii/discuss/1154742/JS-Python-Java-C%2B%2B-or-Simple-Mathematical-Solution-w-Explanation

'''
class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        ans = [0] * n
        a = 1
        z = k + 1
        for i in range(k+1):
            if i % 2:
                ans[i] = z
                z -= 1
            else:
                ans[i] = a
                a += 1
                
        for i in range(k+1,n):
            ans[i] = i + 1
        return ans