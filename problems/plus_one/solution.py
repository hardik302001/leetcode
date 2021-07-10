class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = ""
        for i in digits:
            s = s + str(i)
        n = int(s)
        n+=1
        n = str(n)
        
        l = []
        for i in n:
            l.append(i)
        return l