class Solution(object):
    def minMaxDifference(self, num):
        min_, max_ = str(num), str(num)
        for ch in min_:
            if ch != '0': # ofc the first charcter will be non zero bcz num is integer
                min_ = min_.replace(ch, '0')
                break
        for ch in max_:
            if ch != '9':
                max_ = max_.replace(ch, '9')
                break
        return int(max_) - int(min_)