class Solution:
    def checkRecord(self, s: str) -> bool:
        p =  s.count("A")<2 
        q = ("LLL" in s)
        return p and not q