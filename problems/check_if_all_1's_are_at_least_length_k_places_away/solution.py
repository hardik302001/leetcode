class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        prev = -1
        c = 0
        for i in range(n):
            if nums[i]==0:
                if prev==-1:
                    continue
                else:
                    c+=1
            else:
                if prev==-1:
                    prev = i
                    continue
                if c<k:
                    return False
                prev = i
                c = 0

        return True
                