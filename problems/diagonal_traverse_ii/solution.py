class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        d = Counter()
        n = len(nums)
        for i in range(n):
            for j in range(len(nums[i])):
                if (i+j) not in d:
                    d[i+j] = []
                d[i+j].append(nums[i][j])
        
        # print(d)
        ans = []
        for i in d:
            ans.extend(d[i][::-1])
        
        return ans