'''

#brute force

class SubrectangleQueries:

    def __init__(self, rectangle: List[List[int]]):
        self.r = rectangle        

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                self.r[i][j] = newValue

    def getValue(self, row: int, col: int) -> int:
        return self.r[row][col]
        
'''

# https://leetcode.com/problems/subrectangle-queries/discuss/685352/JavaPython-3-Two-methods%3A-change-input-and-not-w-brief-analysis.
#see the analysis part and comments

class SubrectangleQueries:
    def __init__(self, rectangle: List[List[int]]):
        self.r = rectangle
        self.histories = []

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        self.histories.append([row1, col1, row2, col2, newValue])

    def getValue(self, row: int, col: int) -> int:
        for his in reversed(self.histories):
            if his[0] <= row <= his[2] and his[1] <= col <= his[3]:
                return his[4]
        return self.r[row][col]