#sieve

#r primes = r!
#n-r composites so (n-r)!

# ans =  ( r! + (n-r)!)%m



class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        primes = [True] * (n + 1)
        for prime in range(2, int(math.sqrt(n)) + 1):
            if primes[prime]:
                for composite in range(prime * prime, n + 1, prime):
                    primes[composite] = False
                    
                    
        cnt = 0
        for i in primes:
            if i:
                cnt = cnt + 1
        cnt =cnt -2
        
        return math.factorial(cnt) * math.factorial(n - cnt) % (10**9 + 7)