class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        d = {}
        n = len(nums)
        for i in range(n-1):
            if nums[i]==key:
                if nums[i+1] in d:
                    d[nums[i+1]]+=1
                else:d[nums[i+1]] = 1
        d = [[k, v] for k, v in sorted(d.items(), key=lambda item: item[1])]
        return d[-1][0]