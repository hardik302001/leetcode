class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        
        while target !=1:
            if target%2==0: 
                if maxDoubles>0:
                    maxDoubles -=1
                    target = target //2
                    ans = ans +1
                else:
                    ans = ans + target -1
                    target = 1

            else:
                target -=1
                ans = ans +1
            # print(target)
        return ans