# https://codeforces.com/problemset/problem/405/B

#code idea is from this solution


class Solution:
    def pushDominoes(self, domi: str) -> str:
        dominoes = []
        n = len(domi)
        for i in domi:
            dominoes.append(i)
        state = 'L'
        count = 0
        ans = 0
        ind1 = 0
        ind2 = 0
        
        
        for x in range(n):
            if dominoes[x] == '.':
                count += 1

            if dominoes[x] == 'L':
                if state == 'R':   #situation is like R.....some dots ...L
                                   # so if odd dots then one domono will be left standing else if even then equally RRRRRRRLLLLLLLL situation
                        
                    if count % 2 == 1:
                        for i in range(x-count, x- count + count//2):
                            dominoes[i] = 'R'
                        for i in range(x-count +count//2+1, x):
                            dominoes[i] = 'L'
                        
                    else:
                        for i in range(x-count, x- count + count//2):
                            dominoes[i] = 'R'
                        for i in range(x-count +count//2, x):
                            dominoes[i] = 'L'
                            
                                
                        
                else:            #L.....some dots...L, so all dots will turn into LLLLLLLLLL
                    for i in range(ind1, x+1):
                        dominoes[i] = 'L'
                        
                count = 0
                state = 'L'
                ind1 = x
                


            if dominoes[x] == 'R':
                if state=='R':  #R.....R  , so all R
                    for i in range(ind2,x+1):
                        dominoes[i] = 'R'
                else:               #situation is like R....some dots ...L, no trigger bcz opposite dircetion
                    pass
                count = 0
                state = 'R'
                ind2 = x

                
#after all these 4 cases we have one corner case, if the last state is R, so it means there must be some / no dots
#situation  R.....   and the string is finishes , so we need to trigger position of last left elements
                
                
        if state=='R':
            for i in range(ind2,n):
                dominoes[i]='R'
                
        
            
            # print(dominoes)
        res = ''
        for i in dominoes:
            res+=i
        return res
