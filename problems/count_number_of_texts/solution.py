'''
  ==>  key =  7 , 9 ( uptil size of 4 allowed )

subarray sz = 4
7 7 7 7
77 7 7
7 77 7
7 7 77
77 77
7 777
777 7
7777

count = 8

subarray sz = 5
7 7 7 7 7
77 7 7 7
7 77 7 7
7 7 77 7
7 7 7 77
77 77 7
77 7 77
7 77 77
777 7 7
7 777 7
7 7 777
777 77
77 777
7777 7
7 7777

count 15


  ==>  key =  1 ,2 ,3, 4, 5, 6, 8 ( uptil size of 3 allowed )

subarray sz = 4
1 1 1 1
11 1 1
1 11 1
1 1 11
11 11
1 111
111 1

count = 7

subarray sz = 5
1 1 1 1 1
11 1 1 1
1 11 1 1
1 1 11 1
1 1 1 11
11 11 1
11 1 11
1 11 11
111 1 1
1 111 1
1 1 111
111 11
11 111

count 13


'''


class Solution:
    def countTexts(self, p: str) -> int:
        d = {}
        n = len(p)
        c = 1
        for i in range(1, n):
            if p[i]!=p[i-1]:
                if p[i-1] not in d:
                    d[p[i-1]] = []
                d[p[i-1]].append(c)
                c = 1
            else:
                c+=1
        if p[-1] not in d:
            d[p[-1]] = []
        d[p[-1]].append(c)

       
        prod = 1
        for i in d:
            l = d[i]
            if i =='7' or i=='9':
                for x in l:
                    dp = [0]*(x+10)
                    dp[0] = 1
                    dp[1] = 1
                    dp[2] = 2
                    dp[3] = 4
                    for ind in range(4 , x+1):
                        dp[ind] = dp[ind-1]+dp[ind-2] + dp[ind-3] + dp[ind-4]
                    
                    print(i , x, dp[x])
                    prod*= dp[x]
                    
                    prod%=1000000007
                
            else:
                for x in l:
                    dp = [0]*(x+10)
                    dp[0] = 1
                    dp[1] = 1
                    dp[2] = 2
                    dp[3] = 4
                    for ind in range(4 , x+1):
                        dp[ind] = dp[ind-1]+dp[ind-2]+dp[ind-3]
                    print(i , x, dp[x])
                    prod*= dp[x]
                    prod%=1000000007
        
        return prod%1000000007