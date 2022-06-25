class Solution:
    def countAsterisks(self, s: str) -> int:
        z = s.split('|')
        c = 0
        for i in range(len(z)):
            if i%2==0:
                c+= z[i].count("*")
        return c