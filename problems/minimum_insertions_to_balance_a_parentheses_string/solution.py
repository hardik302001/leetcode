#https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/780221/Python-Simple-and-Fast-or-Time-O(n)-or-Space-O(1)


class Solution:
    def minInsertions(self, s: str) -> int:
        
        count = 0
        s = s.replace('))', '}')
        open_bracket_count = 0

        for c in s:
            if c == '(':
                open_bracket_count += 1
                
            else:
			
                # For ) you need to add 1 char to get ))
                if c == ')': 
                    count += 1

                # Matching ( for ) or ))
                if open_bracket_count:
                    open_bracket_count -= 1


                # No Matching ( for ) or ))
                # Need to insert ( to balance string
                else:
                    count += 1

        return count + open_bracket_count * 2