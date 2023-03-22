# To find the smallest lexicographical permutation, we start with a list of increasing order. All "I"s are already satisfied. With any sequence of continuous 'D''s, we reverse the list. Since the range of the numbers within the sequence is unchanged, the "I"'s are not influenced.

class Solution(object):
    def findPermutation(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        
        l = len(s)
        stack,res = [],[]
        for i in range (l):
            cur_num = i+1
            if s[i] == 'D':
                stack.append(cur_num)
            if s[i] == 'I':
                stack.append(cur_num)
                while stack:
                    res.append(stack.pop())
        # last digit
        res.append(l+1)
        while stack:
            res.append(stack.pop())
            
        return res