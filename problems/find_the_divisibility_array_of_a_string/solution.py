class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        n = len(word)
        div = [0]*n
        cur = 0
        for i in range(n):
            cur = cur*10 + int(word[i])   
            f = 1 if cur%m==0 else 0
            div[i]= (f)
            cur = cur%m    # very important step
        return div