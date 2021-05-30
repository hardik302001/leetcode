class Solution:
    def reverseWords(self, s: str) -> str:
        l =[]
        size = len(s)
        s = s.split()
        print(s)
        for i in s:
            l.append(i)
        l = l[::-1]
        ss = ""
        for i in l:
            ss = ss+ i + " "
        siz = len(ss)
        return ss[:siz-1]