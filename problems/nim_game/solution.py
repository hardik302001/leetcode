#pattern write from 1 to 10
#it lose at 4..
#for 5 6 7 it can remove 1,2 and 3 respectively to reach at 4.

#now its opponent turn..so 4 will be now winning for my player so win


class Solution:
    def canWinNim(self, n: int) -> bool:
        if n%4!=0:
            return True
        else:
            return False