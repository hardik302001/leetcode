class MapSum:
    def __init__(self):
        self.data = dict()
    
	# a dictionary in python already works this way
    def insert(self, key: str, val: int) -> None:
        self.data[key] = val

	# search each key for the prefix and add to a running total
    def sum(self, prefix: str) -> int:
        keys = self.data.keys()
        summation = 0
        
        for k in keys:
            # print(prefix)
            # print(k[:len(prefix)])
            
            if k[:len(prefix)] == prefix:
                summation += self.data[k]
                
        return summation