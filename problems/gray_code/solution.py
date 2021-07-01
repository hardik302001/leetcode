class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]

        result = [0,1]
        iterations = 1
		# calculate till row-1, reverse result and add 2^(iteration -1)
        # [0,1] + [1+2,0+2] => [0,1,3,2]
        # [0,1,3,2] + [2 + 4, 3 + 4, 1 + 4, 0 + 4] => [0,1,3,2,6,7,5,4]
        while iterations < n:
            iterations += 1
            temp = result
            increment_val = 2 ** (iterations-1)
            new_array = []
            for i in range(len(temp)-1, -1, -1):
                result.append(temp[i] + increment_val)
        
        return result