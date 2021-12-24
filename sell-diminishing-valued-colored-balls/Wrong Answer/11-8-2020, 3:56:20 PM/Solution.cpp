// https://leetcode.com/problems/sell-diminishing-valued-colored-balls

class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        vector<int> v;
        long long ans = 0;
        int n = inventory.size();
        for(int c : inventory){
            v.push_back(c);
        }
        sort(v.rbegin(),v.rend());
        
        
        auto get = [&](int x,int y ){
            int cnt = x-y+1;
            if(cnt < orders){
                y = x-orders+1;
            }
            orders -= cnt;
            return (x+y)*cnt/2;
        };
        
        long long curr = 0;
        for(int i = 0;i+1<n;i++){
            if(orders < 0 )break;
            int x = v[i];
            int y = v[i+1];
            int diff = (x-y);
            cout << i << " "<< v[i] << " " << get(x,y+1) << endl;
            ans += get(x,y+1);
            v[i+1] += v[i];
        }
        return ans;
        
    }
};