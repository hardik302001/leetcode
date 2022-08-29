# We just keep track of the index of the added elements, so when we remove them, we copy the last one into it.

# From Python docs (https://wiki.python.org/moin/TimeComplexity) we know that list.append() takes O(1), both average and amortized. Dictionary get and set functions take O(1) average, so we are OK.


class RandomizedSet(object):

    def __init__(self):
        self.nums, self.pos = [], {}
        
    def insert(self, val):
        if val not in self.pos:
            self.nums.append(val)
            self.pos[val] = len(self.nums) - 1      # 0 based indexing
            return True
        return False
        
#most jod thing i have ever seen !

    def remove(self, val):
        if val in self.pos:
            idx, last = self.pos[val], self.nums[-1]
            self.nums[idx] = last          # update val to last element (and we will pop the last now bcz we replaced val by last, now we dont have val in nums. So we also need to remove val from map also and update index of last in map also)
            self.pos[last] = idx           # updating index of last in map, new index of last will be old index of val that is pos[val] (idx)
            
            self.nums.pop()                                  # remove last element from nums
            self.pos.pop(val)                                # remove val from map
            return True
        
        return False
            
        
    def getRandom(self):    # random.randInt chooses a random value frokm given range of indices, and we then return value at that index
        return self.nums[random.randint(0, len(self.nums) - 1)]