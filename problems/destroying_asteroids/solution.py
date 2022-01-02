
'''
**Another way to approach the problem.**
Sort the mass of asteroids.
I always choose the maximum mass asteroid that have less than / equal mass in comparison to  current mass, so I can destroy all asteroids having less / equal mass than the current mass. 
So , I update my cur mass as I destroy all valid asteroid and mark those asteroids as visited.

Now, as my curr mass is updated, I again find the maximum mass asteroid that have less than / equal mass in comparison to  current mass, destroy those valid asteroids and mark them visited.
I repeat this process, until there is no unvisited asteroid that have mass less / equal than cur mass.

Now, if any of the asteroid is visited, it means we cant destroy all asteroids, thus return false, ese return true. 

**TC : O(nlogn) + O(n) =  O(nlogn)**
**SC: O(n)**
    
'''

class Solution:
    def asteroidsDestroyed(self, mass: int, a: List[int]) -> bool:
        a.sort()
        n = len(a)
        vis = [0]*n
        
        while True:
            c = 0
            p = bisect.bisect(a,mass)      # find the index of the asteroid withh mass less than / equal to cur mass.
            for i in range(p-1,-1,-1):
                if vis[i]!=0:
                    break
                vis[i] = 1
                c =c +1
                mass = mass + a[i]

            if c==0:   # there is no new asteroid that is destroyed, thus our curr mass is also not updated, so we will break!
                break
            
            
        for i in range(n):
            if vis[i]==0:
                return 0
        return 1

    
# see cpp soln also