class ParkingSystem:
    l = [0]*3
    def __init__(self, big: int, medium: int, small: int):
        self.bc = big
        self.mc = medium
        self.sc = small

    def addCar(self, carType: int) -> bool:
        if carType==1:
            if self.bc>0:
                self.bc -=1
                return True
            else:
                return False
        elif carType==2:
            if self.mc>0:
                self.mc-=1
                return True
            else:
                return False
        
        elif carType==3:
            if self.sc>0:
                self.sc-=1
                return True
            else:
                return False
