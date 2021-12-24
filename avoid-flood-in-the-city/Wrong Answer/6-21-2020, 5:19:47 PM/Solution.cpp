// https://leetcode.com/problems/avoid-flood-in-the-city

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int cnt =0 ;
        bool safe  = 1;
        vector<int> ans,z ;
        map<int,int> m1;
        for(int c : rains){
            if(c == 0){
                cnt += 1;
                continue;
            }
            if(m1[c] == 0){
                ans.push_back(-1);
                m1[c]++;
            }else if(m1[c] == 1){
                if(cnt > 0){
                    z.push_back(c);
                    ans.push_back(0);
                    cnt--;
                    m1[c]--;
                }else{
                    safe = 0;
                }
            }
        }
        if(!safe) return vector<int>();
        int pos = 0;
        // for(int &c : ans){
        //     if(c == 0){
        //         c = z[pos++];
        //     }
        // }
        return ans;
    }
};