class StringIterator(object):

    def __init__(self, s):
        self.stk=list(s)[::-1]
        self.count=0
        self.curr=""
        
    def next(self):
        if not self.hasNext():
            return ' '
        if self.count==0:#get new letter from stk
            self.curr=self.stk.pop()
            num=0
            while self.stk and self.stk[-1].isdigit():
                num=num*10+int(self.stk.pop())
            self.count=num
        self.count-=1
        return self.curr       

    def hasNext(self):
        return len(self.stk)>0 or self.count>0