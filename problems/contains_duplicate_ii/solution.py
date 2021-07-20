class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i in range(len(nums)):
            if nums[i] in d:
                d[nums[i]].append(i)
            else:
                p = [i]
                d[nums[i]] = p
                
        print(d)
        for i in d:
            if len(d[i])==1:
                continue
            else:
                for j in range(1, len(d[i])):
                    diff = abs(d[i][j] - d[i][j-1])
                    if diff<=k:
                        return True
        return False
                