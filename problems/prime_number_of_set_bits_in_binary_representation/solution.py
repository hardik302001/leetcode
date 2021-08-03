# In the constraints it says that L and R are at most 1,000,000, so the numbers can be at most 20 bits.

class Solution:
    def countPrimeSetBits(self, L, R):
        primes = {2, 3, 5, 7, 11, 13, 17, 19}
        return sum(map(lambda x: bin(x).count('1') in primes, range(L, R+1)))