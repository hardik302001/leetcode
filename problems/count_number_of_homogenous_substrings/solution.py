# same as : https://leetcode.com/problems/number-of-substrings-with-only-1s/submissions/


class Solution:
    def countHomogenous(self, s: str) -> int:
        s += '#'
        p = s[0]
        l = []
        temp = ''
        for i in s:
            if i==p:
                temp += i
            else:
                l.append(temp)
                temp = i
                p = i
        ans = 0
        for i in l:
            ans+= len(i)*(len(i)+1)//2
        return ans%1000000007