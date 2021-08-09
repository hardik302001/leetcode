'''
IDK why but this is so unintuituve

An intuitive approach will be to group the binary string into chunks of 0s and 1s (sort of like compressing). The answer will be simply to sum the min of length of neighboring chunks together.

Here are some examples:

'00001111' => [4, 4] => min(4, 4) => 4
'00110' => [2, 2, 1] => min(2, 2) + min(2, 1) => 3
'10101' => [1, 1, 1, 1, 1] => 4


#we are taking min of both because suppose 111000, so we can have 10, 1100, 111000 so 3
#other example 111001000, so we will ahve 10 , 1100, 01, 10
#because the min will contribute uptil no of min we have consecutively!


'''

class Solution(object):
    def countBinarySubstrings(self, s):
        chunks, consecutive, res = [], 1, 0
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                consecutive += 1
            else:
                chunks.append(consecutive)
                consecutive = 1
        chunks.append(consecutive)
        for i in range(1, len(chunks)):
            res += min(chunks[i], chunks[i - 1])
        return res