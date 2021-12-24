// https://leetcode.com/problems/open-the-lock

class Solution {
public:
    vector<string> get(string s){
        vector<string> res;
        for(int i = 0;i<4;i++){
            string t = s;
            if(t[i] == '9'){
                t[i] = '0';
            }else{
                t[i]++;
            }
            res.push_back(t);
            t = s;
            if(t[i] == '0'){
                t[i] = '9';
            }else{
                t[i]--;
            }
            res.push_back(t);
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        map<string,int> d,all;
        for(string s : deadends){
            d[s] +=1;
        }
        queue<pair<int,string>> qq;
        if(d["0000"]!=0)qq.push({0,"0000"});
        int ans = -1;
        while(qq.size()){
            pair<int,string> pp = qq.front();
            string t = pp.second;
            qq.pop();
            
            vector<string> res = get(t);
            for(string s : res){
                if(d[s] == 0 && all[s] == 0){
                    all[s]+=1;
                    qq.push({pp.first+1,s});
                    if(s == target){
                        ans = pp.first+1;
                        break;
                    }
                }
            }
        }
        return (ans ==-1 ? -1 : ans);
    }
};