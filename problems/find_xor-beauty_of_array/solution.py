# odd bit ones would contribute to xor
# we will get bit ones for 3 cases ( 1 1 1 , 1 0 1 , 0 1 1)
# idea by codingMohan

class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(32):
            ones = 0
            zero = 0
            for x in nums:
                if( (1<<i)&x):
                    ones+=1
                else:
                    zero+=1
            total_triplet_with_set_bit = (ones*ones*ones + ones*zero*ones + zero*ones*ones)     
            if total_triplet_with_set_bit&1:
                ans+= (1<<i)
                
                
        return ans


'''

# nice explanation : https://leetcode.com/problems/find-xor-beauty-of-array/discuss/3015014/Why-just-XOR-of-all-numbers-works

class Solution:
    def xorBeauty(self, nums: List[int]) -> int:
        x = 0
        for i in nums:x = x ^i
        return x
'''