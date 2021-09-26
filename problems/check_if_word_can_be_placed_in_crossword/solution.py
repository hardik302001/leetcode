class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        
        p = []
        for row in board:
            s = ""
            for ind in row:
                if ind=="#":
                    if len(s)>0:
                        p.append(s)
                    s = ""
                else:
                    s = s + ind
            if len(s)>0:
                p.append(s)
        
        for i in p:
            if len(i)==len(word):
                j = 0
                f = 1  
                for el in range(len(i)):
                    if i[el]==word[el] or i[el]==" ":
                        continue
                    else:
                        f = 0
                        break
                if f:return True
                
                j = len(word)-1
                f = 1
                for el in range(len(i)):
                    if i[el]==word[len(i) - el -1] or i[el]==" ":
                        continue
                    else:
                        f = 0
                        break
                if f:return True
                    
        newboard = []
        for i in range(n):
            l = []
            for j in range(m):
                l.append(board[j][i])
            newboard.append(l)
            
            
            
            
         
        p = []
        for row in newboard:
            s = ""
            for ind in row:
                if ind=="#":
                    if len(s)>0:
                        p.append(s)
                    s = ""
                else:
                    s = s + ind
            if len(s)>0:
                p.append(s)
       
        for i in p:
            if len(i)==len(word):
                j = 0
                f = 1  
                for el in range(len(i)):
                    if i[el]==word[el] or i[el]==" ":
                        continue
                    else:
                        f = 0
                        break
                if f:return True
                
                j = len(word)-1
                f = 1
                for el in range(len(i)):
                    if i[el]==word[len(i) - el -1] or i[el]==" ":
                        continue
                    else:
                        f = 0
                        break
                if f:return True
                
                
        return False