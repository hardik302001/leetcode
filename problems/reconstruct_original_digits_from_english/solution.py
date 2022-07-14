# on the basis of unique occurence

class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        words=[['z','zero',0],['x','six',6],['s','seven',7],['v','five',5],\
                ['g','eight',8],['f','four',4],['h','three',3],\
                ['w','two',2],['o','one',1],['i','nine',9]]
        d={}
        for c in s:
            if c not in d:
                d[c]=0
            d[c]+=1
        res=[]
        for k,word,num in words:
            if k in d:
                v=d[k]
                for c in word:
                    d[c]-=v
                    if d[c]==0:
                        del d[c]
                res.append(str(num)*v)
        return ''.join(sorted(res))