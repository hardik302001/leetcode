class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        if arr==[]:
            return []
        p = []
        for i, v in enumerate(arr):
            p.append([v, i])
        p.sort()
        
        pp = []
        x = 1
        prev = p[0][0]
        for i in p:
            if i[0]==prev:
                pp.append([i[0] , i[1] , x])
            else:
                x+=1
                prev = i[0]
                pp.append([i[0] , i[1] , x])
        # print(pp)
        pp.sort(key = lambda x: (x[1]))
        
        ans =[]
        for i in range(len(pp)):
            ans.append(pp[i][2])
        return ans
            