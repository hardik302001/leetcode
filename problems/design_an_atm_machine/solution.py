class ATM:

    def __init__(self):
        self.d = [0]*5
        self.p = [500, 200 , 100 , 50 , 20]
        

    def deposit(self, bc: List[int]) -> None:
        bc = bc[::-1]
        for i in range(5):
            self.d[i]+=bc[i]
        # print(self.d)
        

    def withdraw(self, a: int) -> List[int]:
        self.d2 = self.d[:]
        self.ans = []
        for i in range(5):
            if(self.d2[i]>0 and self.p[i]<=a):
                x = min(self.d2[i] , (a//self.p[i]))
                a-=x*self.p[i]
                self.d2[i]-=x
                self.ans.append(x)
                
                if(x==0):
                    return [-1]
            else:
                self.ans.append(0)
                continue
        if a==0:
            self.d = self.d2
            return self.ans[::-1]
        else:
            return [-1]
            
                
            


# Your ATM object will be instantiated and called as such:
# obj = ATM()
# obj.deposit(banknotesCount)
# param_2 = obj.withdraw(amount)