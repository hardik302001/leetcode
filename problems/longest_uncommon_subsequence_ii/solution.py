class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def issubseq(str1, str2):
            m = len(str1)
            n = len(str2)

            j = 0    # Index of str1
            i = 0    # Index of str2
            while j < m and i < n:
                if str1[j] == str2[i]:
                    j = j+1
                i = i + 1

            return j == m        
        
        
        
        if len(set(strs))==1:
            return -1
        else:
            strs.sort(key = len, reverse = True)
            for i in range(len(strs)):
                c = 0
                p = strs[i]
                for j in range(len(strs)):
                    if issubseq(p,strs[j]):
                        c = c +1

                if c==1:
                    return len(p)
            return -1
            