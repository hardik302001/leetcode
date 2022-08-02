# there is also an  O(n) solution, some optimisation in map , something , see that also


# ---------------------------------------------------------------------------------

# idea : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623726/C%2B%2B-O(n)-Solution
# O(n^2)

class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        d = {}
        d[0] = [-1]
        ans = 0
        
        x = 0
        for i in range(n):
            x = x^arr[i]
            if x in d:
                for ind in d[x]:
                    start = ind+1
                    end = i
                    ans += (end-start)
                    
                d[x].append(i)
            else:
                d[x] = [i]
        return ans


# ---------------------------------------------------------------------------
# O(n^3) , pref xor
'''
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        n = len(arr)
        x = [0]*(n+1)
        for i in range(n):
            x[i+1] = x[i]^arr[i]

        c = 0
        for i in range(n-1):
            for j in range(i+1, n):
                for k in range(j, n):
                    a = x[j]^x[i]
                    b = x[k+1]^x[j]
                    if a==b:
                        c+=1
                    
        return c
'''