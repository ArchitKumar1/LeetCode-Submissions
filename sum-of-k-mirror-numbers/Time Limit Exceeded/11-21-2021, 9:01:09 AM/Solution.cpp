// https://leetcode.com/problems/sum-of-k-mirror-numbers

class Solution {
public:
    long long kMirror(int k, int n) {
        queue<string> q;
        q.push("");
        for(int i = 0;i <=9;i++){
            q.push(to_string(i));
        }
        int mx = min(2 + n/2,9);
        vector<long long> pali;
        set<string> m1;
        pali.reserve(1000000);
        while(q.size()){
            
            string t = q.front();q.pop();
            if(t.size() > mx ) continue;
            if(m1.find(t) != m1.end()) continue;
            m1.insert(t);
            
            if(t.size() && stoll(t) > 0 && t[0] != '0') pali.push_back(stoll(t));
            for(int i = 0;i <=9;i++){
                q.push(to_string(i) + t + to_string(i));
            }
        }
        sort(pali.begin(),pali.end());
        // cout << pali.size();
        vector<long long> ks;
        vector<long long> commons;
        for(auto c : pali){
            string nnum;
            auto d = c;
            while(c){
                nnum += '0'+ (c % k);
                c /= k;
            }
            string rnnum = nnum;
            reverse(nnum.begin(),nnum.end());
            if(rnnum == nnum){
                // cout << nnum << endl; 
                commons.push_back(d);
            }
        }
        for(auto c : commons){
            cout << c << endl;
        }
        cout << endl;
        assert(commons.size() >= n);
        long long fans = 0;
        for(int i = 0;i < n;i++){
            fans += commons[i];
        }
        return fans;
    }
};