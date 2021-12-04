class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        if startValue >= target :
            return startValue - target
        else:
            ans = 0
            while target>startValue:
                if target &1:
                    target = target +1
                else:
                    target = target //2
                ans = ans +1
            return ans + startValue - target