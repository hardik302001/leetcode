class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        def check(big, small):
            print(big , small)
            n = len(small)
            i0 = 0
            i1 = 0
            e0 = len(small)-1
            e1 = len(big) -1
            fi = 1
            fe = 1
            while i0 <= e0 and i1<= e1:
                if fi and small[i0]==big[i1]:
                    i0+=1
                    i1+=1
                else:
                    fi = 0
                
                if fe and small[e0]==big[e1]:
                    e0-=1
                    e1-=1
                else:
                    fe = 0
                
                if not fi and not fe :
                    return 0
            
            return 1
        
        s1 = sentence1.split(" ")
        s2 = sentence2.split(" ")
        
        if s1==s2:
            return True
        else:
            m = max(len(s1), len(s2))
            if m==len(s1):
                if check(s1, s2):
                    return 1
                    
            else:
                if check(s2, s1):
                    return 1
            return 0
                    
                
                