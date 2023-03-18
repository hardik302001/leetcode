# Note that the first nut to be picked needs not necessarily be the nut closest to the squirrel's start point, but it's the one which maximizes the savings.

class Solution:
    def minDistance(self, height, width, tree, squirrel, nuts):
        def taxi(p, q):
            return abs(p[0] - q[0]) + abs(p[1] - q[1])
    
        S = sum(2 * taxi(tree, nut) for nut in nuts)
        
        return S + min(taxi(squirrel, nut) - taxi(nut, tree) for nut in nuts)
#                     min(  squireel goes to nut - dist bw nut and tree )