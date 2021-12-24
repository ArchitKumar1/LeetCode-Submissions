// https://leetcode.com/problems/watering-plants

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n  = plants.size();
        int steps = 0;
        
        int cap = capacity;
        for(int i = 0 ;i < n;i++){
            if(plants[i] > cap){
                steps += 2*i;
            }
            cap -= plants[i];
            steps += 1;
        }
        return steps;
    }
};