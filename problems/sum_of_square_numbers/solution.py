class Solution:
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        sq = set()
        count = int(math.sqrt(c))
        # use (count + 1) because first index is 0
        for i in range(count + 1):
            sq.add(i ** 2)

        for n in sq:
            if c - n in sq:
                return True

        return False