'''
First of all, only the length of the string matters, not its content. This is due to the fact that the problem is symmetric with respect to flipping of 1-to-0 and 0-to-1.
Next, the result of flipping of any k-substring will be unique, i.e., produce different strings. This is due to the fact that the operation of flipping bits is reversible.
Finally, we note that there are P=len(s)-k+1 starting positions. At each position, we can choose to flip or not flip. Thus, the answer would be to raise 2 to the power P.
'''

class Solution:
    def countDistinctStrings(self, s: str, k: int) -> int:
        return pow(2 , len(s)-k+1, 1000000007)