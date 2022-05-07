# also see kinda similar : https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/submissions/
# just replace right side occurence to n, as for appeal we only need to count once, we want distinct , we dont want unique...
# so we have only left side barrier, and free till index n n right side..


# see for more info : https://leetcode.com/problems/total-appeal-of-a-string/discuss/1997337/Pictorial-explanation-linear-solution.-Question-with-similar-approach



class Solution:
    def appealSum(self, s: str) -> int:
        d = {}
        n = len(s)
        for i in range(n):
            if s[i] not in d:
                d[s[i]] = [-1]
            d[s[i]].append(i)
        
        c = 0
        for i in d:
            l = d[i]
            for x in range(1 , len(l)):
                c+= (l[x]-l[x-1]) * (n-l[x])           # right barier is n 
        return c