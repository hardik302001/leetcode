class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        output = 0
        counter = [0] * (32)
        
        for num in set(nums):
            bit_one_count = self.count_number_of_bit_one(num)    # Number of bit of A OR B + A AND B = number of bit of A + number of bit of B.
            counter[bit_one_count] += 1
        
        for i in range(0, 32):
            for j in range(0, 32):
                if i + j >= k:
                    output += counter[i] * counter[j] 
                    
        return output
        
    def count_number_of_bit_one(self, number: int) -> int:
        output = 0 
        while number:
            number &= number - 1
            output += 1
        return output