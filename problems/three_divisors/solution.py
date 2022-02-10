# square of prime

class Solution:
    def isThree(self, n: int) -> bool:
        def prime(n):
            if n==2 or n==3: return True
            if n%2==0 or n<2: return False
            for i in range(3, int(n**0.5)+1, 2):   # only odd numbers
                if n%i==0:
                    return False    

            return True
        p = int(n**0.5)
        return p*p==n and prime(p)