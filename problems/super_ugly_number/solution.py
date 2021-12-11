#same as ugly number 11





    
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        size = len(primes)
        ugly = 1
        dp = [1]
        index = [0]*size
        ugly_nums = [1] * size
        
        for i in range(1, n):
            # compute possibly ugly numbers and update index
            for j in range(0, size):
                if ugly_nums[j] == ugly:
                    ugly_nums[j] = dp[index[j]] * primes[j]
                    index[j] += 1
            # get the minimum
            ugly = min(ugly_nums)
            dp.append(ugly)
        return dp[-1]