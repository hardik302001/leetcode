

class Solution:
    def categorizeBox(self, l: int, w: int, h: int, m: int) -> str:
        four = 10000
        nine =  10**9
        bulk = 0
        heavy = 0
        if (l>=four or w>=four or h>=four or l*w*h>=nine) : bulk = 1
        if m>=100 : heavy = 1
        
        if bulk and heavy: return "Both"
        if not bulk and not heavy: return "Neither"
        if bulk and not heavy: return "Bulky"
        if heavy and not bulk: return "Heavy"
        
        