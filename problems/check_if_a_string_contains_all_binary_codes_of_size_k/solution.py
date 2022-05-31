'''
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        se = set()
        n = len(s)
        for i in range( k-1 , n):
            p =s[i-k+1:i+1]
    
            if p not in se:
                se.add(p)
    
        return len(se)==2**k
    

# TC : O(nk)
# SC: O(2^n*k)
    
'''

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        n = len(s)
        need = 2**k # there are total 2^k binary codes of length k
        seen = [False] * need # seen[x] is to check if value x is existed as substring length k of string `s`
        clearKthBitMask = need - 1 # mask to clear bit at k_th
        # bcz it have only k chars , so when we will do "&", it wil consider only latest k elements and ignore prev elements 
        
        val = 0
        for i in range(n): 
            val = (val << 1) & clearKthBitMask | int(s[i])   
            # print(val)
            if i-k+1 >= 0 and seen[val] == False:
                seen[val] = True
                need -= 1
                
        return need == 0
        
        
        
    
# follow up 
    
'''
Given a binary string s and an integer k.
Return True if all binary code of length k is a subsequence of s. Otherwise, return False.    
    
    
    def hasAllCodes(self, s: str, k: int) -> bool:
        # lee215's follow-up. subsequence instead of substring
        i, n = 0, len(s)
        while i < n and k > 0:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            k -= 1 if j < n else 0
            i = j + 1
        return k == 0
    

Explain answer by @poweric
To construct all combination of length k, you need:
k = 1: 01 or 10
k = 2: 0101 or 1010
k = 3: 010101 or 101010
...
Ask a result, its 01|01|01... k pairs of 01 or k pairs of 10, so you can always choose 0 or 1 from each pair.
Similarly, for k = 2, the following pairs are equivalent:
0101 1010 1001 0110


'''