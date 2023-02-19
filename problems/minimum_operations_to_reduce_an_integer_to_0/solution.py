# see cpp soln

class Solution:    
    def minOperations(self, n: int) -> int:
        if n==0 or (n and (not(n & (n - 1)))):
            return 1
        
        bi = bin(n)[2:]
        s1 = '0' + bi
        s2 = bi
        s1 = list(s1)
        print(bi)
        ans = n.bit_count()
        def solve(s):
            x = 0
            i = len(s)-1
            while i>=0:
                if s[i]=='1':
                    c = 0
                    for j in range(i , -1, -1):
                        if s[j]=='1':
                            c+=1
                        else:
                            break
                    
                    # now j is '0'
                    if c>1:
                        x+=1          # adding
                        s[j] = '1'
                        for k in range(j+1 , len(s)):
                            if s[k]=='1':
                                s[k] = '0'
                            else:
                                break
                        i == j
                    else:
                        i-=1
                else:
                    i-=1
            
            
                    
            return x + s.count('1')
        ans = min(ans ,   solve(s1))
        return ans