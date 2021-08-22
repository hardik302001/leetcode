class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        
        ans = []
        def generateAllBinaryStrings(n, arr, i):
 
            if i == n:
                p = ''
                for el in arr:
                    p = p + str(el)
                ans.append(p)
                return

            # First assign "0" at ith position
            # and try for all other permutations
            # for remaining positions
            arr[i] = 0
            generateAllBinaryStrings(n, arr, i + 1)

            # And then assign "1" at ith position
            # and try for all other permutations
            # for remaining positions
            arr[i] = 1
            generateAllBinaryStrings(n, arr, i + 1)
            
        n = len(nums[0])
        arr = [0] * n
 
        generateAllBinaryStrings(n, arr, 0)
        s1 = set(nums)
        s2 = set(ans)
        x = s2 -s1
        l =list(x)
        return l[0]
    