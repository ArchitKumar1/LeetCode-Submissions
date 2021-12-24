// https://leetcode.com/problems/grid-illumination


class Solution {
    #define PB push_back;
    

public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int,int> r,c,d1,d2;
        map<pair<int,int>,int> m1;
        for(int I = 0;I<lamps.size();I++){
            int i = lamps[I][0];
            int j = lamps[I][1];
            r[i]+=1,c[j]+=1,d1[i+j]+=1,d2[i-j]+=1;
            m1[{i,j}] = 1;
        }
        vector<int> ans;
        
        for(auto v : queries){
            int i = v[0];
            int j = v[1];
            int t = 0;
            if( r[i] || c[j] || d1[i+j] || d2[i-j]) t = 1;
            ans.push_back(t);
            
            for(int i =-1;i<=1;i++){
                for(int j =-1 ;j<=1;j++){
                    if(m1[{i,j}] >= 1){
                        int I = m1[{i,j}] - 1;
                        r[i]--;c[j]--;d1[i+j]--;d2[i-j]--;
                    }
                }
            }
            

        }
        return ans;
    }
};