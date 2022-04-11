class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        p = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        s = set()
        for word in words:
            ans = ''
            for e in word:
                ans+=p[ord(e)-ord('a')]
            s.add(ans)
        return len(s)