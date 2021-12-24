// https://leetcode.com/problems/design-underground-system

class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,int>> counts;
    map<int,pair<string,int>> pass;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pass[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> p = pass[id];
        pair<int,int> &pc = counts[{p.first,stationName}];
        pc.first += (t - p.second);
        pc.second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int> pc = counts[{startStation,endStation}];
        return 1.0*pc.first/pc.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */