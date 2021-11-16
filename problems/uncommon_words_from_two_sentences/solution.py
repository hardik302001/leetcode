class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans = []
        a = s1.split()
        b = s2.split()
        
        for i in a:
            if i not in b:
                if a.count(i)==1:
                    ans.append(i)
            
        for i in b:
            if i not in a:
                if b.count(i)==1:
                    ans.append(i)  
            
        return ans