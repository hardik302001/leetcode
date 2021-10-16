class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alice = colors.split('B')
        bob = colors.split('A')
       
        ca = 0
        cb = 0
        for i in alice:
            if len(i)>2:
                ca+= len(i)-2
        for i in bob:
            if len(i)>2:
                cb+= len(i)-2
        if ca>cb:
            return 1
        else:
            return 0