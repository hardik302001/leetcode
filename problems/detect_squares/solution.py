class DetectSquares:

    def __init__(self):
        self.d = {}

    def add(self, point: List[int]) -> None:
        x = point[0]
        y = point[1]
        p = (x,y)
        if p in self.d:
            self.d[p]+=1
        else:
            self.d[p] = 1

    def count(self, point: List[int]) -> int:
        # print(self.d)
        alp = point[0]
        bet = point[1]
        pp = (alp,bet)
        ans = 0
        corner = []
        for p in self.d:
            # print(p)
            x = p[0]
            y = p[1]
            
            if x>alp and y>bet:
                if abs(x-alp)  == abs(y-bet):
                    corner.append(p)
            if x<alp and y>bet:
                if abs( alp-x)  == abs(y - bet):
                    corner.append(p)
            if x<alp and y<bet:
                if abs(alp-x)  == abs(bet-y):
                    corner.append(p) 
            if x>alp and y<bet:
                if abs( x-alp)  == abs(bet-y):
                    corner.append(p)        
        
        # print(corner)
        
        for corn in corner:
            x = corn[0]
            y = corn[1]
            cor = self.d[corn]
            ae = 0
            be = 0
            if (alp,y) in self.d:
                ae = ae + self.d[(alp,y)]
            if (x,bet) in self.d:
                be = be + self.d[(x,bet)]
            ans = ans + ae*be*cor
                
        
        
        
        
        
        
        
        
        
        
        
#         #first quad
#         ae = 0
#         be = 0
#         corn = 0
#         for p in self.d:
#             # print(p)
#             x = p[0]
#             y = p[1]
            
#             if x>alp and y>bet:
#                 if abs(x-alp)  == abs(y-bet):
#                     corn +=self.d[p]
                    
#             elif x>alp and y==bet:
#                 be+=self.d[p]
#             elif y>bet and x == alp:
#                 ae+=self.d[p]
#         ans = ans + (ae*be*corn)
        
#         #second quad
#         ae = 0
#         be = 0
#         corn = 0
#         for p in self.d:
#             x = p[0]
#             y = p[1]
            
#             if x<alp and y>bet:
#                 if abs( alp-x)  == abs(y - bet):
#                     corn +=self.d[p]
                    
#             elif x<alp and y==bet:
#                 be+=self.d[p]
#             elif y>bet and x == alp:
#                 ae+=self.d[p]
#         ans = ans + (ae*be*corn)
        
#         #third quad
#         ae = 0
#         be = 0
#         corn = 0
#         for p in self.d:
#             x = p[0]
#             y = p[1]
#             # print(x,y)
            
#             if x<alp and y<bet:
#                 if abs(alp-x)  == abs(bet-y):
#                     corn +=self.d[p]
                    
#             elif x<alp and y==bet:
#                 be+=self.d[p]
#             elif y<bet and x == alp:
#                 ae+=self.d[p]
#         # print("third")
#         # print(ae,be,corn)
#         ans = ans + (ae*be*corn)
        
        
#         #fourth quad
#         ae = 0
#         be = 0
#         corn = 0
#         for p in self.d:
#             x = p[0]
#             y = p[1]
            
#             if x>alp and y<bet:
#                 if abs( x-alp)  == abs(bet-y):
#                     corn +=self.d[p]
                    
#             elif x>alp and y==bet:
#                 be+=self.d[p]
#             elif y<bet and x == alp:
#                 ae+=self.d[p]
#         ans = ans + (ae*be*corn)
        
        return ans
        


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)