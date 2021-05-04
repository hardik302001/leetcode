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