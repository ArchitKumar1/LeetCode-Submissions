// https://leetcode.com/problems/expressive-words

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        vector<pair<char,int>>v1,vc;
        int n = S.size();
        for(int i = 0;i<n;i++){
            int cnt = 1;
            char c = S[i];
            while(i+1<n && S[i+1]==c){
                i++;
                cnt += 1;
            }
            v1.push_back({c,cnt});
        }
        for(string w : words){
            vc.clear();
            n = w.size();
            for(int i = 0;i<n;i++){
                int cnt = 1;
                char c = w[i];
                while(i+1<n && w[i+1]==c){
                    i++;
                    cnt += 1;
                }
                vc.push_back({c,cnt});
            }
            if(vc.size() != v1.size()){
                continue;
            }else{
                bool safe = 1;
                for(int i =0;i<v1.size();i++){
                    auto [x1,c1] = v1[i];
                    auto [x2,c2] = vc[i];
                    cout << x1 << " " << c1 << endl;
                    cout << x2 << " " << c2 << endl;
                    cout << endl;
                    safe&= x1 == x2;
                    safe&= (c2 <=c1) &&( c1-c2!= 1);
                }
                if(safe){
                    ans++;
                }
            }
        }
        return ans;
    }
};