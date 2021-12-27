class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        d = {}
        for i in logs:
            if i[0] not in d:
                d[i[0]] = set()
            d[i[0]].add(i[1])
        
        ans = [0]*k
        for i in d:
            l = len(d[i])
            ans[l-1]+=1
        return ans