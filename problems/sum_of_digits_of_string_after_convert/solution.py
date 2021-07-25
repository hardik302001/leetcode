import string

class Solution:
    def getLucky(self, s: str, k: int) -> int:
        alp = 'abcdefghijklmnopqrstuvwxyz'
        ss = ''
        for i in s:
            ss +=str(alp.index(i)+1)
        # print(ss)
        
        for i in range(k):
            sum = 0
            for ii in ss:
                sum+= int(ii)
            sum = str(sum)
            ss=sum
        return int(ss)