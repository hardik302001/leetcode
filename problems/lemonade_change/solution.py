class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = 0
        ten = 0
        twen = 0
        
        n = len(bills)
        
        for i in bills:
            if i==5:
                five+=1
            elif i==10:
                if five:
                    five -= 1
                    ten += 1
                else:
                    return False
            else:
                if ten:
                    if five:
                        five -= 1
                    else:
                        return False
                    
                    ten-=1
                    twen+=1
                else:
                    if five>=3:
                        five-=3
                    else:
                        return False
                    twen+=1
            # print(five, ten, twen)
        return True
                