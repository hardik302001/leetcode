class Solution:
    def minimumRefill(self, p: List[int], capa: int, capb: int) -> int:
        n = len(p)
        i = 0
        j = n-1
        a = capa
        b = capb
        c = 0
        while i<=j:
            if i==j:
                if a >= b:
                    if a>=p[i]:
                        a = a - p[i]
                    else:
                        c = c +1
                        a = capa
                        a = a - p[i]
                else:
                    if b>=p[i]:
                        b = b - p[i]
                    else:
                        c = c +1
                        b = capb
                        b = b - p[i]
            else:
                if a>=p[i]:
                    a = a - p[i]
                else:
                    c = c +1
                    a = capa
                    a = a - p[i]
                if b>=p[j]:
                    b = b - p[j]
                else:
                    c = c +1
                    b = capb
                    b = b - p[j]                
                
                    
            i = i +1
            j = j - 1
        return c