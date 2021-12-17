#We maintain the runnig product in the prefix array. To get the product for the last k elements, we divide the last running product by the product that was k - 1 steps ago.

# Important observation: if we add zero, we reset the prefix array. All products that includes zero will be zero. So, we can just check if k is greater than the size of our previx array, and return zero in that case.

# class ProductOfNumbers:
#     def __init__(self):
#         self.data = []
#         self.product = 1

#     def add(self, num: int) -> None:
#         if num != 0:
#             self.product *= num
#             self.data.append(self.product)
#         else:                                          #reset
#             self.data = []
#             self.product = 1

#     def getProduct(self, k: int) -> int:
#         if len(self.data) < k:
#             return 0
#         if len(self.data) == k:
#             return self.data[-1]
#         else:
#             return int(self.data[-1] / self.data[-1-k])
        
        
        
    
# other soln, can be that if yuou dont want to reset the array , then keep track of latest zero index!
class ProductOfNumbers:
    def __init__(self):
        self.nums = [1]
        self.zero = -1

    def add(self, num: int) -> None:
        if num == 0 or self.nums[-1] == 0:
            if num == 0:             # kepp track of last zero
                self.zero = len(self.nums)-1
                
            self.nums.append(num)                # if zero, then append 0, else append num (bcz the pref prod would be zero , so we kinda want to reset)
        else:    #if it is not  zero, or prev prod is also not zero, then continue calculating the pref prod
            self.nums.append(num*self.nums[-1])

    def getProduct(self, k: int) -> int:
        if len(self.nums) - k -1 <= self.zero: return 0
        elif self.nums[-k-1] == 0: return self.nums[-1]
        else: return self.nums[-1] // self.nums[-k-1]