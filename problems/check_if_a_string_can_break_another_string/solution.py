class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        def check(s1, s2):       # s1 >= s2
            s1 = sorted(s1) 
            s2 = sorted(s2)
      
            # print(s1, s2)
            for i in range(len(s1)):
                if s1[i]<s2[i]:
                    return False
            return True
        
        
        return check(s1, s2) or check(s2, s1)