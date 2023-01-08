import copy
class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        d1 = {}
        d2 = {}
        for i in word1:
            if i in d1:
                d1[i]+=1
            else:
                d1[i] = 1
        for i in word2:
            if i in d2:
                d2[i]+=1
            else:
                d2[i] = 1
        
        # print(d1, d2)
        for i in d1:
            for j in d2:
                # print(i , j)
                
                nd1 = copy.deepcopy(d1)
                nd2 = copy.deepcopy(d2)
                # print(d1 , d2 , nd1 , nd2 , i, j)

                nd1[i]-=1
                if j in nd1:
                    nd1[j]+=1
                else:
                    nd1[j] = 1
                nd2[j]-=1
                if i in nd2:
                    nd2[i]+=1
                else:
                    nd2[i] = 1

                # print(d1, d2, nd1 , nd2)
                f1 = 0
                f2 = 0
                c1 = 0
                c2 = 0
                for q in nd1: 
                    if nd1[q]>=1:
                        c1+=1
                for q in nd2:
                    if nd2[q]>=1:
                        c2+=1

                if c1==c2:
                    # print(nd1, nd2)
                    return True
        return False