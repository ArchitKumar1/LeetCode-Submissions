// https://leetcode.com/problems/number-of-boomerangs

class Solution {
public:
    inline double dist(pair<int,int> &p,pair<int,int> &q){
        return sqrt((1.0)*(q.first - p.first)*(q.first - p.first) + (1.0)*(q.second - p.second)*(q.second - p.second));
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = points.size();
        int boom= 0,boom2 = 2;
        unordered_map<double,int> m1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)
                    continue;
                m1[dist(points[i],points[j])]++;
            }
            for(auto it : m1){
            if(it.second > 1){
                boom += it.second  * (it.second - 1);
                }
            }
            m1.clear();
        }
        return boom;
    }
};