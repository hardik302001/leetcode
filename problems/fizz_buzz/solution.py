class Solution(object):
    def fizzBuzz(self, n):
        return ['Fizz'*(not i%3) + 'Buzz'*(not i%5) + str(i)*((i%3 and i%5) > 0) for i in range(1, n+1)]