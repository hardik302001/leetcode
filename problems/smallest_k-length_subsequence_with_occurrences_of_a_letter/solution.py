'''
similar to : https://leetcode.com/problems/remove-duplicate-letters/
idea : https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/discuss/1784636/PYTHON-or-BEATS-88-or-O(N)-or-WELL-EXPLAINED-or-MONOTONIC-STACK

'''

class Solution:
    def smallestSubsequence(self, s: str, k: int, letter: str, repetition: int) -> str:
        left = s.count(letter)
        n = len(s)
        stack = list()

        for i in range(n):
            c = s[i]

            while stack and stack[-1] > c and n - i + len(stack) > k or (c == letter and k - len(stack) < repetition):
                last = stack[-1]
                # if the last char in the stack == letter and the number of letter left in s
                #is less or equal to repetition that means if i popped the letter i can't
                #end up with sbsq with repetition letter, that's why we break from the loop
                if letter == last and left <= repetition:   
                    break       

                #if it is not we just pop from the stack
                stack.pop()

                #if the popped char == letter we increase number of repetition (bcs it represent
                #the number of letter i still need to add to the stack)
                if last == letter: repetition += 1

            #with the same logic if the current char equal to letter -->
            # dec repetition and decrement the number of occurances of letter i still have
            #in my string s
            if c == letter:
                repetition -= 1
                left -= 1

            stack.append(c)

        return "".join(stack[: k])