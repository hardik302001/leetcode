class Solution:
    def reformatDate(self, date: str) -> str:
        m = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
        mon = {v:str("0" + str(i+1))[-2:] for i,v in enumerate(m)}
        
        date , month , year = date.split()
        inti = date[:-2]
        date = str("0" + inti)[-2:]
        month = mon[month]
        
        return year + "-" + month + "-" + date