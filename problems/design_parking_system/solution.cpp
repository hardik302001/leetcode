class ParkingSystem {
public:
    
    int bn , mn, sn;
    ParkingSystem(int big, int medium, int small) {
        bn = big;
        mn = medium;
        sn = small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(bn>0){ bn--;return true;}
            else{return false;}
        }
        else if(carType==2){
            if(mn>0){ mn--;return true;}
            else{return false;}
        }
        else if(carType==3){
            if(sn>0){ sn--;return true;}
            else{return false;}
        }
        
        
        return false;     // bcz return type is bool
    }
    
};

