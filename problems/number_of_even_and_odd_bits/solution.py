class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        b = bin(n)[2:]
        b = b[::-1]
        e = 0
        o = 0
        for i in range(len(b)):
            if b[i]=='1':
                if i&1:o+=1
                else  :e+=1
        return [e,o]
            