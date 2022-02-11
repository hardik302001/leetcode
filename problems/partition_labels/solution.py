
#  https://leetcode.com/problems/partition-labels/discuss/298474/Python-two-pointer-solution-with-explanation

# TC: O(n)
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
    

# O(n)
    
'''

https://leetcode.com/problems/merge-intervals/submissions/

How about an approach using intervals. Compute interval (start, end) for each letter [a-z] , where start is first occurrence of letter, and end is last occurrence of letter. Then we merge any overlapping intervals, and the resulting intervals can form the answer.
'''

'''
class Solution(object):
    def partitionLabels(self, s):
        
        def merge(intervals):
            intervals.sort()
            merged = []
            for i in range(len(intervals)):
                if merged == []:
                    merged.append(intervals[i])
                else:
                    previous_end = merged[-1][1]
                    current_start = intervals[i][0]
                    current_end = intervals[i][1]
                    if previous_end >= current_start: # overlap
                        merged[-1][1] = max(previous_end,current_end)     #either current end can be less / more than prev end, so we take max of both
                    else:
                        merged.append(intervals[i]) #no overlap

            ans = []
            # print(merged)
            for i in merged:
                ans.append((i[1]-i[0]+1))
            return ans
        
        
        intervals = []  
        se = set(s)
        for i in se:
            beg = s.index(i)
            end = s.rindex(i)
            intervals.append([beg, end])
        res = merge(intervals)
        return res
        
'''