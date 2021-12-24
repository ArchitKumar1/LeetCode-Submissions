// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        multiset<int> r,l;
        int n = events.size();
        vector<array<int,3>> v;
        
        int ans = 0;
        for(int i = 0;i < n;i++){
            v.push_back({events[i][1],-1,events[i][2]});
            v.push_back({events[i][0]-1,1,events[i][2]});
            r.insert(events[i][2]);
            ans=max(ans,events[i][2]);
        }
    
        sort(v.begin(),v.end());
        for(auto arr: v){
            cout << arr[0] << " " << arr[1] << " " <<arr[2] << endl;
            int t = arr[1];
            int va = arr[2];
            if(t == -1){
                l.insert(va);
            }else{
                r.erase(r.find(va));
            }
            int L = l.size() ? *prev(l.end()) : 0;
            int R = r.size() ? *prev(r.end()) : 0;
            ans = max(L + R,ans);
            cout << ans << " "  << l.size() << " " << r.size() << endl;
            cout << endl;
        }
        cout << endl;
        return ans;
        
    }
};