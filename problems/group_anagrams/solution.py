# sort all strings, if string are anagrams, then after sorting they are same..
# for optimization we will use dictionary having key as the sorted string, and we will add anagrams in list as values in that key..


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        p = []
        for i in strs:
            ss = sorted(i)
            q = ''
            for sss in ss:
                q = q + sss
            p.append([q,i])
            
            
        print(p)
        d = {}
        for i in p:
            if i[0] in d:
                d[i[0]].append(i[1])
            else:
                d[i[0]] = [i[1]]
        ans = d.values()
        return ans