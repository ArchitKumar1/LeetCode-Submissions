// https://leetcode.com/problems/minimum-number-of-frogs-croaking

class Solution {
public:
    int minNumberOfFrogs(string cf) {
        string c = "croak";
        vector<int> cnt(300,0);
        int mini = 0;
        bool ok = 1;
        for(int i =0 ;i<cf.size();i++){
            for(int j = 0;j<c.size();j++){
                bool safe = 1;
                if(c[j] ==cf[i]){
                    if(j>0) safe&= (cnt[c[j-1]] >= (cnt[c[j]] + 1));
                }else{
                    continue;
                }
                if(safe == 1){
                    cnt[cf[i]]++;
                }
            }
            mini = max(mini,cnt[c[0]] - cnt[c[c.size()-1]]);
        }
        int ans = 0;
        
        for(int i = 0;i<c.size();i++){
            cout << cnt[c[i]] << endl;
            if(cnt[c[i]] != cnt[c[0]]) ok = 0;
        }
        return (ok ? mini: -1);
    }
};