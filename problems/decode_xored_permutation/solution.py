#  https://leetcode.com/problems/decode-xored-permutation/discuss/1031080/simple-solution-with-picture

class Solution:
    def decode(self, encoded: List[int]) -> List[int]:        
        xor_all_elements, xor_except_last_element = 0, 0
        
        
        # read ques again
        for val in range(1, len(encoded)+2): 
            xor_all_elements ^= val
            
        for i, val in enumerate(encoded):
            if i%2: continue
            xor_except_last_element ^= val
        
        # xor_all_elements ^ xor_except_last_element = the last element of the original array
        ans = [xor_all_elements ^ xor_except_last_element]
        for val in encoded[::-1]:
            ans.append(ans[-1] ^ val)
        return ans[::-1]
            