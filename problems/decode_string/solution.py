#  TOWER OF HANOI

# also see: https://leetcode.com/discuss/interview-question/1392284/solving-tower-of-hanoi-using-the-magic-of-recursion
# It takes 2power n -1 steps!
# see gfg , there ae tons of resources for it!

class Solution(object):
    def decodeString(self, s):
        stack = []; curNum = 0; curString = ''
        for c in s:
            if c == '[':
                stack.append(curString)   #keep prev string in stack
                stack.append(curNum)
                curString = ''             #now inirialize a new string, we will put all char between [...] in this string
                curNum = 0
           
            elif c == ']':
                num = stack.pop()   #previous added element was the num in stack
                prevString = stack.pop()  #before that we had the prev result string in stack
                curString = prevString + num*curString  #we append this new string to previous string now..and thi is our new string! 
            elif c.isdigit():
                curNum = curNum*10 + int(c)
            else:
                curString += c
        return curString
    