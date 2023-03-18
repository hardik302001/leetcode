class Solution:
    def badSensor(self, sensor1: List[int], sensor2: List[int]) -> int:
        n = len(sensor1)
        for i in range(n):
            if sensor1[i] != sensor2[i]:
                if i == n - 1:
                    return -1
                elif sensor1[i] == sensor2[i + 1] and sensor1[i + 1] == sensor2[i]:
                    pass
                elif sensor1[i] == sensor2[i + 1]:
                    return 1
                elif sensor1[i + 1] == sensor2[i]:
                    return 2
        return -1