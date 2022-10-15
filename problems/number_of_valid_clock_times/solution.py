class Solution:
    def countTime(self, time: str) -> int:
        def valid(time, s):
            for i in range(len(time)):
                if time[i]!='?':
                    if time[i]!=s[i]:
                        return 0
            
            hr =  10* int(s[0]) +  int(s[1]) 
            mn = 10*int(s[3]) + int(s[4])
            
            if 0<=hr and hr<=23 and 0<=mn and mn<=59:
                return 1
            return 0
        
            
        c = 0
        for i in range(10):
            for j in range(10):
                for k in range(10):
                    for l in range(10):
                        s = str(i) + str(j) + ":" + str(k) + str(l)
                        if valid(time , s):
                            c+=1
        return c
                            