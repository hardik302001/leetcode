class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        l = []
        for i in s.split():
            if i.isnumeric():
                l.append(int(i))
       
        for i in range(1,len(l)):
            if l[i-1]<l[i]:
                continue
            else:
                return False
        return True
            