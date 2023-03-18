class Solution:
    def distMoney(self, money: int, children: int) -> int:
        money = money - children
        if money<0: return -1
        seven = min(children , money//7)
        money = money - seven*7
        
        eight = seven
        child_left = children-eight    
        
        if (child_left==1 and money==3) or (child_left==0 and money>0):
            return eight-1
        else:
            return eight