class Solution:
    def sortJumbled(self, m: List[int], nums: List[int]) -> List[int]:
        a = []
        ind = 0
        for i in nums:
            p  = ''
            for x in str(i):
                p += str(m[int(x)])
            p = int(p)
            a.append([p, ind, int(i)])
            ind+=1
        a = sorted(a)
        print(a)
        ans = []
        for i in a:
            ans.append(i[2])
        return ans