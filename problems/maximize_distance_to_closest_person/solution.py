class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        c = 0
        m = 0
        n =len(seats)
        
        first = seats.index(1)
        last = seats[::-1].index(1)
        
        ans = max(first, last)
        # print(seats[first: n-last-1])
        for i in range(first +1, n - last ):
            if seats[i]==1:
                m = max(m , c)
                c = 0
            else:
                c =c +1
            # print(c)
        ans= max(ans , (m-1)//2+1)
        return ans