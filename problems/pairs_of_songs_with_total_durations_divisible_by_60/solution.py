class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        d = {}
        for i in time:
            if i%60 in d:
                d[i%60]+=1
            else:
                d[i%60] = 1
        print(d)
        count = 0
        for i in range(1, 30):
            if i in d and (60-i) in d:
                count += d[i] * d[60 - i]
        for i in [0, 30]:
            if i in d:
                count += (d[i] - 1) * d[i] // 2
        return count