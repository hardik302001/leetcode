# The issue with traditional 2 pointer approach was that we were only looing at the first charcters and then comparing , if they are equal then we dont know which one to conisder, so we need to traverse in both strings until we get the tie breaker and then see which one was lexograpphic larger..Yeah we can do it....
# But why to take so much pblm when we have inbuilt string comparater that compares string lexographically , so we use it directly!


# If one character is larger in one of the words, choose that one. The tricky part is, if the characters are the same, you always should choose the lexicographically larger string. You can directly use string comparison in python as it's built-in and fast.


# just dry run second tc to understand it better!
'''
Input: word1 = "abcabc", word2 = "abdcaba"
Output: "abdcabcabcaba"

word1       word2
=====       ======
            
            abdc
abc
abc
            aba
            
Merge = abdcabcabcaba
'''
class Solution:
    def largestMerge(self, word1, word2):
        ans = ''
        while word1 and word2:
            if word1>word2:
                ans += word1[0]
                word1 = word1[1:]
            else:
                ans += word2[0]
                word2 = word2[1:]
        ans += word1
        ans += word2
        return ans