class Solution:
    def minimumLength(self, s: str) -> int:
        n = len(s)
        i = 0
        j = n-1
        while i<j:
            p = s[i]
            q = s[j]
            if p!=q:
                return j-i+1
            
            while i+1<j:
                if s[i+1]==p:
                    i = i+1
                else:
                    break

            # print(i)
            while j-1>i:
                if s[j-1]==q:
                    j = j -1
                else:
                    break
            # print(j)
            
            i = i +1
            j = j -1
            
            
            # print(s[i:j+1])
            
        if i==j:return 1   #bcz i==j, bcz then either of left or right prefix will be empty
        else: return 0     #now i>j, so it means all elents are same