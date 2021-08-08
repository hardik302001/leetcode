class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        p = ''
        x = len(s)
        
        for i in words:
            p = p + i
            if len(p)>x:
                return False
            if len(p)==x and p==s:
                return True
        return False