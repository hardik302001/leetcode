class Solution:
    def findMissingRanges(self, A, lower, upper):
        result = []
        A.append(upper+1)
        pre = lower - 1
        for i in A:
           if (i == pre + 2):
               result.append(str(i-1))
           elif (i > pre + 2):
               result.append(str(pre + 1) + "->" + str(i -1))
           pre = i
        return result