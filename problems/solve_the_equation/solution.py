# very similar ro fraction addition and subtraction



class Solution:
    def solveEquation(self, s: str) -> str:
        l = list(s.replace("+"," +").replace("-"," -").split("="))[0].split()
        r = list(s.replace("+"," +").replace("-"," -").split("="))[1].split()
        print(l)
        print(r)
        x = 0
        left = 0
        for i in l:
            if 'x' in i:
                if i[0]=='+':
                    p = i[1:-1]
                    if len(p)>0:
                        x = x + int(p)
                    else:
                        x = x + 1
                    
                elif i[0]=='-':
                    p = i[1:-1]
                    if len(p)>0:
                        x = x - int(p)
                    else:
                        x = x - 1                    
                else:
                    p = i[:-1]
                    if len(p)>0:
                        x = x + int(p)
                    else:
                        x = x + 1
            else:
                left+= int(i)
        # print(left,x)
        for i in r:
            if 'x' in i:
                if i[0]=='+':
                    p = i[1:-1]
                    if len(p)>0:
                        x = x - int(p)
                    else:
                        x = x - 1
                    
                elif i[0]=='-':
                    p = i[1:-1]
                    if len(p)>0:
                        x = x + int(p)
                    else:
                        x = x + 1                    
                else:
                    p = i[:-1]
                    if len(p)>0:
                        x = x - int(p)
                    else:
                        x = x - 1
            else:
                left-= int(i)
                
        # print(left,x)
        if x==0 and left==0:
            return "Infinite solutions"
        elif x==0:
            return "No solution"
        else:
            return "x=" + str(-1*left//x)
        