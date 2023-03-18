class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        
        if cars==1:
            return min(ranks)
        
        l = 1
        r = 10**18
        ranks.sort()
        ans = r
        
        def check(m):
            c = 0

            for i in ranks:
                tot = m
                cur = tot//i
                car = int(cur**(0.5))
                if car**2>cur:
                    car-=1
                c+=car
            return c>= cars
               
            
        while l<r:
            m = (l+r)//2
            if check(m):
                ans = m
                r =m
            else:
                l = m+1
        return ans