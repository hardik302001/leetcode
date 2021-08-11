#same as ugly number 11




class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        res = [1]
        p = [0]*len(primes)   #for index to keep track  of ith prime in primes array
        s = len(primes)
        while len(res)<n:
            m = 1000000000000000
            for i in range(s):    
                m = min(m, primes[i]*res[p[i]])
            res.append(m)
            for i in range(s):
                if primes[i]*res[p[i]]==m:
                    p[i]+=1
        print(res)
        return res[n-1]