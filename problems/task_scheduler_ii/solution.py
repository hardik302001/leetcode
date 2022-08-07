class Solution:

    def taskSchedulerII(self, a: List[int], s: int) -> int:

        g = Counter()

        z = 0

        for x in a:

            if x not in g:

                z += 1

            else:

                z = max(z, g[x] + s) + 1

            g[x] = z

        return z
        