# class Solution:
#     def maximizeGreatness(self, nums: List[int]) -> int:
#         d = Counter(nums)
#         pre = -1
#         ans = 0
#         d = list([i , d[i]] for i in d)
#         d.sort()
       
#         for i , f in d:
#             if pre==-1:
#                 pre = f
#             else:
#                 m = min(pre , f)
#                 pre -= m
#                 ans+=m
#                 pre = pre + f
#         return ans
            
    
    
class Solution:
    def maximizeGreatness(self, A):
        A.sort()
        res = 0
        for a in A:
            if a > A[res]:
                res += 1
        return res