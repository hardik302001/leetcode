class MinStack:

    def __init__(self):
        self.stack = []
        self.m = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.m == []:
            self.m.append(val)
        else:
            if self.m[-1]>=val:
                self.m.append(val)

    def pop(self) -> None:
        end = self.stack[-1]
        self.stack.pop()
        if end==self.m[-1]:
            self.m.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.m[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()