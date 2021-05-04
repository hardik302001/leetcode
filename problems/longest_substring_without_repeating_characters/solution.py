class Solution:
 def lengthOfLongestSubstring(self, s: str) -> int:
        i = j = max_len = 0
        ss = set()
        while j < len(s):
            if s[j] in ss:
                ss.remove(s[i])
                i+=1
            else:
                ss.add(s[j])
                j+=1
                max_len = max(max_len, j-i)  
        return max_len