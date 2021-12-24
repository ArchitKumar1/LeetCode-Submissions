// https://leetcode.com/problems/profitable-schemes

class Solution {
public:
    
    int mod = pow(10,9) + 7;
    int n;
    unordered_map<string,int> m1;
    string get(int g,int p,int curr){
        string ans = to_string(g) + "#" + to_string(p) + "#" + to_string(curr);
        return ans;
    }
    int solve(int g ,int p,int curr,vector<int>&group,vector<int>&profit,int G,int P){
        
        if(curr == n){
            if(g <=G && p>=P){
                return 1;
            }else{
                return 0;
            }
        }
        string ans =get(g,p,curr);
       // cout << ans << endl;
        //if(g>G) return m1[ans] = 0;
        if(m1.find(ans)!=m1.end()) return m1[ans];
        int total = (solve(g,p,curr+1,group,profit,G,P) +
                  solve(g+group[curr],p + profit[curr],curr+1,group,profit,G,P))%mod;
        
        return  m1[ans] = total;
    }
    
    
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        n = group.size();
        return solve(0,0,0,group,profit,G,P);
        
    }
};