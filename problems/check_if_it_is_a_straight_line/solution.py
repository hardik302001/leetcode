class Solution:
    def checkStraightLine(self, coordinates):

        if len(coordinates) == 2:
            return True
        A, B = coordinates[0][1] - coordinates[1][1], coordinates[1][0] - coordinates[0][0]
        C = -A*coordinates[0][0] - B*coordinates[0][1]
        for point in coordinates:
            if A*point[0] + B*point[1] + C != 0:
                return False
        return True