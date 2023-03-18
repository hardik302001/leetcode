class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        dct=collections.Counter(nums[:k])
        res=[len(dct)]
        for i in range(k,len(nums)):
            dct[nums[i]]+=1
            dct[nums[i-k]]-=1
            if dct[nums[i-k]]==0: del dct[nums[i-k]]
            res.append(len(dct))
        return res
