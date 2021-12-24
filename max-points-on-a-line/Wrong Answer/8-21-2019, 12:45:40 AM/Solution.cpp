// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<double,int> m1;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x2-x1 == 0){
                    m1[0]++;
                }else{
                    double d = (1.0)*(y2-y1)/((1.0*(x2-x1)));
                    m1[d]++;
                    m1[d]++;
                    cout << "KIA\n";
                }
            }
        }
        int ans = 0;
        for(auto x : m1){
            cout << x.first << " " << x.second << endl;
            ans = max(ans,x.second);
        }
        int fans = 0;
        for(int i=1;i<ans;i++){
            if(i*(i-1) == ans){
                fans = i;
                break;
            }
        }
        cout << ans <<  " " << fans << endl;
        return fans;
    }
};