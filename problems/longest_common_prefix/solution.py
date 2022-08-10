# just compare first and last, after sorting

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        if len(strs)==1:
            return strs[0]
        cp = ''
        
        strs.sort()
        a = strs[0]
        b = strs[-1]
  
        for i in range(len(a)):
            if a[i]==b[i]:
                cp = cp + a[i]
            else:
                return cp
        return cp





# no need to compare all

'''
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs)==0:
            return ""
        if len(strs)==1:
            return strs[0]
        cp = ''
        l = [len(st) for st in strs] #lengths for each string
        for i in range(min(l)): # scan from first letter to min str lengths
            tmp = [s[i] for s in strs] #get i-th letter from each string
            if len(set(tmp))==1: #check if all of them are the same
                cp = cp + tmp[0]
            else:
                return cp
        return cp
    
'''