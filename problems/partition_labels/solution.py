# also see first solution  : uses merge intervals

# this solution uses concept from SOLUTION SECTIOn!

#  https://leetcode.com/problems/partition-labels/discuss/298474/Python-two-pointer-solution-with-explanation


class Solution(object):
    def partitionLabels(self, S):
        rightmost = {c:i for i, c in enumerate(S)}
        left, right = 0, 0

        result = []
        for i, letter in enumerate(S):

            right = max(right,rightmost[letter])

            if i == right:
                result += [right-left + 1]
                left = i+1

        return result