class Solution:
    def largestPalindromic(self, num: str) -> str:
        d = Counter()
        for i in num:  d[int(i)]+=1
        
        mid = -1
        ans = ''
        for i in range(9,-1, -1):
            if d[i]&1:
                mid = i
                break
        
        for i in range(9, -1, -1):
            ans += str(i)*(d[i]//2)
        
        if len(ans) and ans[0]=='0' and ans[-1]=='0':
            if mid==-1: return "0"    # bcz we have to return atleast one digit
            else      : return str(mid)
        
        return ans + ans[::-1] if mid==-1 else ans + str(mid) + ans[::-1]
        
     