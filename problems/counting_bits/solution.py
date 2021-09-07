# https://leetcode.com/problems/counting-bits/discuss/79557/How-we-handle-this-question-on-interview-Thinking-process-%2B-DP-solution

class Solution:
    def countBits(self, num: int) -> List[int]:
        result= [0]*(num + 1)
        offset = 1;
        for index in range(1,num+1):
            if (offset * 2 == index):
                offset *= 2
            result[index] = result[index - offset] + 1;
    
        return result;
    
    
    
    
    
   