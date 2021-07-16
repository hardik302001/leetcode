class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        res = []
        n = len(nums)
        for i in range(n):
            for j in range(i+1,n):
                cur = nums[i] + nums[j]
                s = j+1
                e = n-1
                need = target - cur
                while s<e:
                    if nums[s] + nums[e]==need:
                        x = []
                        x.append(nums[i])
                        x.append(nums[j])
                        x.append(nums[s])
                        x.append(nums[e])
                        if x in res:
                            pass
                        else:
                            res.append(x)
                        s = s +1
                        e = e -1
                    elif nums[s] + nums[e]>need:
                        e = e -1
                    else:
                        s = s +1
        return res
                