class Solution:
    def wateringPlants(self, plants: List[int], cap: int) -> int:
        s = 0
        cur = cap
        pos = -1
        n = len(plants)
        i =0
        cost = []
        while i<n:
            if plants[i] <= cur:
                cur = cur - plants[i]
                cost.append((i-pos))
                pos = i
                i = i +1
            else:
                cur = cap
                cost.append(i)
                cost.append(i)
        # print(cost)
        return sum(cost)
                
                