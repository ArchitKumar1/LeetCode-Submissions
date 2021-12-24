// https://leetcode.com/problems/soup-servings

class Solution {
    unordered_map<int, unordered_map<int, double>> data;
public:
    double search(int A, int B) {
        if (data[A].find(B) != data[A].end()) return data[A][B];
        
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1;
        if (B <= 0) return 0;
        
        double p = search(A-100, B) + search(A-75, B-25) + search(A-50, B-50) + search(A-25, B-75);
        p /= 4.0;
        
        return data[A][B] = p;
    }
    
    double soupServings(int N) {
        if (N >= 5000) return 1.0;
        
        return search(N, N);
    }
};