class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        d = Counter()
        for i in s:
            d[i]+=1
        
        
        return (d[letter]*100)//len(s)