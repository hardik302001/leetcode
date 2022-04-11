# USING SET


# class MyHashSet:

#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self.s = set()
        

#     def add(self, key: int) -> None:
#         self.s.add(key)

#     def remove(self, key: int) -> None:
#         self.s.discard(key)

#     def contains(self, key: int) -> bool:
#         """
#         Returns true if this set contains the specified element
#         """
#         return (key in self.s)

# using visited array

class MyHashSet:

    def __init__(self):
        self.arr = [False] * 1000001

    def add(self, key):
        self.arr[key] = True

    def remove(self, key):
        self.arr[key] = False

    def contains(self, key):
        return self.arr[key]