// https://leetcode.com/problems/number-of-orders-in-the-backlog

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>> buypq;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> sellpq;
        
        for(auto x : orders){
            if(x[2] == 1){
                int P = x[0];
                int A  = x[1];
                
                while(A > 0 && buypq.size() > 0 && buypq.top().first >= P ){
                    auto[p,a] = buypq.top(); buypq.pop();
                    if(a >= A){
                        a-= A;
                        A = 0;
                    }else{
                        
                        A -= a;
                        a = 0;
                    }
                    if(a > 0){
                        buypq.push({p,a});
                    }
                }
                if(A > 0) sellpq.push({P,A});
                
            }else{
                int P = x[0];
                int A  = x[1];
                
                while(A > 0 && sellpq.size() > 0 && sellpq.top().first <= P ){
                    auto[p,a] = sellpq.top(); sellpq.pop();
                    if(a >= A){
                        a-= A;
                        A = 0;
                    }else{
                        
                        A -= a;
                        a = 0;
                    }
                    if(a > 0){
                        sellpq.push({p,a});
                    }
                }
                if(A > 0){
                    buypq.push({P,A});
                }
            }
        }
        long long  ans = 0;
        int mod = 1e9+7;
        while(sellpq.size() > 0){
            ans += sellpq.top().second;
            ans %= mod;
            sellpq.pop();
        }
        while(buypq.size() > 0){
            ans += buypq.top().second;
            ans %= mod;
            buypq.pop();
        }
        return ans;
        
    }
};