class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        odd = []
        ev = []
        for i in range(len(nums)):
            if i&1:
                odd.append(nums[i])
            else:
                ev.append(nums[i])
        odd.sort(reverse = True)
        ev.sort()
        
        x = 0
        y = 0
        ans = []
        for i in range(len(nums)):
            if i&1:
                ans.append(odd[x])
                x = x + 1
            else:
                ans.append(ev[y])
                y = y + 1
        return ans