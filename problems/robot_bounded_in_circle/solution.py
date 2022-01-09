# Actually simulating until 4 times the length of string is sufficient, because the worse case we can have is the string contains only instructions for quarter of circle. My Python3 AC solution below:

class Solution:
    def isRobotBounded(self, s: str) -> bool:
        # repeat the instructions 4 times and check if we are at the origin
        s *= 4
        origin = (0,0)
        # directions in clockwise direction: N W S E
        dirs = [(0,1), (-1,0), (0,-1), (1,0)]
        init_dir = 0
        curr_cor = (0,0)
        for i in range(len(s)):
            if s[i] == "G":
                curr_dir = dirs[init_dir]
                curr_cor = (curr_cor[0] + curr_dir[0], curr_cor[1] + curr_dir[1])
            elif s[i] == "L":
                init_dir = (init_dir + 1) % 4
            else:
                init_dir = (init_dir - 1) % 4
        return curr_cor == (0,0)