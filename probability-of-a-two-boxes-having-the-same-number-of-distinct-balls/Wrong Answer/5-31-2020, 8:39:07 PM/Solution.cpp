// https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls

class Solution {
public:
    vector<int>B;
    int n;

    int tsum = 0;
    map<vector<int>,int> m1;
    
    
    vector<long long int>f;
    pair<int,int> ans = {0,0};
    void pre(){
        f.assign(10,1);
        for(int i= 2;i<10;i++){
            f[i] = f[i-1]*i;
        }
    }
    void solve(vector<int> cnt){
        if(m1[cnt] == 1) return;
        m1[cnt] = 1;
        
        int c1= 0,c2= 0 ;
        int sum = 0;
        
        for(int i = 0;i<n;i++){
            if(cnt[i] > 0) c1++;
            if(B[i]-cnt[i] > 0) c2++;
            sum += cnt[i];
        }
        if(sum == tsum/2){
            long long int ff = f[tsum/2];
            for(int i = 0;i<n;i++){
                if(B[i]-cnt[i] > 0){
                    int x = B[i] - cnt[i];
                    ff/=f[x];
                }
            }
            
            if(c1 == c2 ){
                ans.first += ff;
            }
            else ans.second += ff;
            cout << ff << endl;
        }
        
        for(int c : cnt){
            cout << c << " ";
        }
        cout << endl;
        
        
        for(int i =0;i<n;i++){
            if(cnt[i]+1<=B[i]){
                cnt[i]+=1;
                solve(cnt);
                cnt[i]-=1;
            }
        }
        return;;
    }
    double getProbability(vector<int>& balls) {
        pre();
        B = balls;
        n = balls.size();
        for(int c : balls) tsum += c;
        vector<int> base(n,0);
        solve(base);
        cout << ans.first << " " << ans.second << endl;
        return 1.0*ans.first/(ans.first+ ans.second);
        
    }
};