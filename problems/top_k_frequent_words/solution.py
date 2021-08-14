class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = {}
        for i in words:
            if i in d:
                d[i]+=1
            else:
                d[i] =1 
        #first sort on basis of dec freq nad then lexographical order
        d = sorted(d.items() , key = lambda x: (-x[1],x[0]))
        
        ans = []
        for i in range(k):
            ans.append(d[i][0])
        
        return ans
        