// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
public:
    vector<int> v,curr;
    
    ParkingSystem(int b,int m,int s) {
        v = {b,m,s};
        curr = vector<int>(3,0);
    }
    
    bool addCar(int c) {
        c -= 1;
        if(curr[c]+1<=v[c]){
            curr[c]++;
            return 1;
        }else{
            return 0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */