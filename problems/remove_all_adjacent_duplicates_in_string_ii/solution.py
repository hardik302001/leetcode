class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = [['#', 0]]
        for c in s:
            if stack[-1][0] == c:
                stack[-1][1] += 1  #we are not adding new...we are updating it only.
                if stack[-1][1] == k:
                    stack.pop()
            else:
                stack.append([c, 1])
            #print(stack)
        res = ""
        for c,k in stack:
            res = res + c*k
        return res
       