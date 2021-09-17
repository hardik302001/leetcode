#https://leetcode.com/problems/intersection-of-two-arrays-ii/discuss/282372/Java-solution-with-all-3-follow-up-questions



# class Solution(object):
#     def intersect(self, nums1, nums2):
#         n1, n2, res = sorted(nums1), sorted(nums2), []
#         p1 = p2 = 0
#         while p1 < len(n1) and p2 < len(n2):
#             if n1[p1] < n2[p2]:
#                 p1 += 1
#             elif n2[p2] < n1[p1]:
#                 p2 += 1
#             else:
#                 res.append(n1[p1])
#                 p1 += 1
#                 p2 += 1
#         return res
    
    
    
    
# O(nlogn) above soln


class Solution(object):
    def intersect(self, nums1, nums2):
        d = {}
        ans = []
        for i in nums1:
            if i in d:
                d[i]+=1
            else:
                d[i] = 1
        for i in nums2:
            if i in d:
                if d[i]>0:
                    ans.append(i)
                    d[i]-=1
        return ans





# class Solution(object):
#     def intersect(self, nums1, nums2):
#         l = nums1&nums2
#         print(l)
        
        
        