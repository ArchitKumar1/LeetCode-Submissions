// https://leetcode.com/problems/watering-plants-ii

class Solution {
public:
    int minimumRefill(vector<int>& p, int ca, int cb) {
        int n=p.size();
        int i =0,j=n-1;
        int a=ca,b=cb;
        int ans = 0;
        while(i <= j){
            if(i == j){
                if(a == b){
                    if(a < p[i]) a=ca,ans++;
                    a-=p[i];
                    i++;
                }else{
                    if(a < b){
                        if(a < p[i]) a=ca,ans++;
                        a-=p[i];
                    }else{
                        if(b < p[j]) b=cb,ans++;
                        b-=p[j];
                    }
                }
                break;
            }
            if(a < p[i]) a=ca,ans++;
            a-=p[i];
            if(b < p[j]) b=cb,ans++;
            b-=p[j];
            i++,j--;
        }
        return ans;
    }
};