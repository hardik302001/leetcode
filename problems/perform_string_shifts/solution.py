class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:

        # Count the number of left shifts. A right shift is a negative left shift.
        left_shifts = 0
        for direction, amount in shift:
            if direction == 1:
                amount = -amount
            left_shifts += amount
            
        # Convert back to a positive, do left shifts, and return.
        left_shifts %= len(s)
        s = s[left_shifts:] + s[:left_shifts]
        return s