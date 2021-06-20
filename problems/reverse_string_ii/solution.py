class Solution:
    def reverseStr(self, s, k):                
        s = [s[i:i+k] for i in range(0, len(s), k)]
        for i in range(0, len(s), 2):
            s[i] = s[i][::-1]
		# Join array of substrings into one string and return 
        return ''.join(s)