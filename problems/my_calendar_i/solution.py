class MyCalendar(object):
    def __init__(self):
        self.calendar = []

    def book(self, start, end):
        for s, e in self.calendar:
            if s < end <e or s<= start < e or start < e <end or start<= s < end:
                return False
        self.calendar.append((start, end))
        return True