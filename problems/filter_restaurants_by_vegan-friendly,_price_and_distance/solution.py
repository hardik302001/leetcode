class Solution:
    def filterRestaurants(self, r: List[List[int]], v: int, mp: int, md: int) -> List[int]:
        r.sort(key  = lambda x: (-x[1] , -x[0]))
        print(r)
        ans = []
        for i in r:
            if i[3]<=mp and i[4]<=md:
                if (v and i[2]) or not v: 
                    ans.append(i[0])
        return ans