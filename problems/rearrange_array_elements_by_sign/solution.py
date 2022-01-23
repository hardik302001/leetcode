class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        e = []
        o = []
        for i in nums:
            if i<0:
                o.append(i)
            else:
                e.append(i)
        print(e)
        print(o)
        ans =[]
        for i in range(len(nums)//2):
            ans.append(e[i])
            ans.append(o[i])
        return ans