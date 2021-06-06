class Solution(object):
    def intersect(self, nums1, nums2):
        n1, n2, res = sorted(nums1), sorted(nums2), []
        p1 = p2 = 0
        while p1 < len(n1) and p2 < len(n2):
            if n1[p1] < n2[p2]:
                p1 += 1
            elif n2[p2] < n1[p1]:
                p2 += 1
            else:
                res.append(n1[p1])
                p1 += 1
                p2 += 1
        return res