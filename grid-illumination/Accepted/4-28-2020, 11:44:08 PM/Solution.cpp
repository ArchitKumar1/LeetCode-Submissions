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
            m1[{i,j}] += 1;
        }
        vector<int> ans;
        
        for(auto v : queries){
            int i = v[0];
            int j = v[1];
            int t = 0;
            if( r[i] || c[j] || d1[i+j] || d2[i-j]) t = 1;
            ans.push_back(t);
            
            for(int x =i-1;x<=i+1;x++){
                for(int y =j-1 ;y<=j+1;y++){
                    if(m1[{x,y}] >= 1){
                        int t = m1[{x,y}];
                        m1[{x,y}] -=t;
                        r[x]-=t;c[y]-=t;d1[x+y]-=t;d2[x-y]-=t;
                    }
                }
            }
            

        }
        return ans;
    }
};