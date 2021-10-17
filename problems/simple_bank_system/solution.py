class Bank:

    def __init__(self, balance: List[int]):
        self.d = {}
        self.n = len(balance)
        for i in range(len(balance)):
            self.d[i] = balance[i]

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if 1<=account1<=self.n and 1<=account2<=self.n:
            rem  = self.d[account1-1]
            if rem>=money:
                self.d[account1-1] -= money
                self.d[account2-1] += money
                return True
            else:
                return False
        else:
            return False

    def deposit(self, account: int, money: int) -> bool:
        if 1<=account<=self.n:
            self.d[account-1]+=money
            return True
        else:
            return False

    def withdraw(self, account: int, money: int) -> bool:
        if 1<=account<=self.n:
            rem  = self.d[account-1]
            if rem>=money:
                self.d[account-1] -= money
                return True
            else:
                return False
        else:
            return False


# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)