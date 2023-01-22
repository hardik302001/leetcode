'''
       or xor
0 0 -  0 0
0 1 -  1 1 / 1 0 / 0 1
1 0 -  1 1 / 1 0 / 0 1
1 1 -  1 0 / 0 1




01 and 10  can be changed to 11
and 
11 can be changed to 01 and 10 , thus 01-10-11 are interchangeable

'''


class Solution:
    def makeStringsEqual(self, s: str, t: str) -> bool:
        p = []
        n =len(s)
        for i in range(n):
            p.append([int(s[i]), int(t[i])])
        p.sort()
        
        oo =0
        oz = 0
        zo = 0
        zz = 0
        for i in p:
            x = i[0]
            y = i[1]
            if x==1 and y==1:
                oo = 1
            elif x==1 and y==0:
                oz = 1
            elif x==0 and y==1:
                zo =1
            else:
                zz = 1
                
        for i in p:
            x = i[0]
            y = i[1]
            
            if x!=y:
                if x==0:
                    if oo or oz:
                        oo = 1
                        oz = 1
                        zo = 1
                    else:
                        return 0 
                elif x==1:
                    if oo or zo:
                        oo = 1
                        oz = 1
                        zo = 1
                    else:
                        return 0
        return 1
            
# or the other way is
# If any of the string has all 0's we can't convert it to another.
            
'''
    def makeStringsEqual(self, s: str, target: str) -> bool:
        if s.count('1') == 0 or target.count('1') == 0:
            return s == target
        return True

'''