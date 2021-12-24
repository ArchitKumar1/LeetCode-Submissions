// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
public:
    int b ,m,s;
    ParkingSystem(int big, int medium, int small) {
         b = big,m = medium,s = small;
    }
    
    bool addCar(int c) {    
        if(c == 1){
            if(b>0){
                b--;return 1;
            }else{
                return 0;
            }
        }
        if(c == 2){
            if(m>0){
                m--;return 1;
            }else{
                return 0;
            }
        }
        if(c == 3){
            if(s>0){
                s--;return 1;
            }else{
                return 0;
            }
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */