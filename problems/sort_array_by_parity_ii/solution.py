class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        odd = 1
        even = 0
        result = [0]*len(A)
        for num in A:
            if num%2==0:
                result[even] = num
                even += 2
            else:
                result[odd] = num
                odd += 2
        return result