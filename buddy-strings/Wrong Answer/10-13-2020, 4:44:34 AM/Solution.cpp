// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> v;
        vector<int> cnts(26,0);
        int cnt = 0;
        for(int i = 0;i<A.size();i++){
            cnts[A[i]-'a']++;
            if(A[i]!= B[i]){
                cnt += 1;
                v.emplace_back(i);
            }
        }
        
        if(cnt > 2){
            return 0;
        }
        if(cnt == 0){
            for(int i = 0;i<26;i++){
                if(cnts[i] > 1) return 1;
            }
            return 0;
        }
        if(cnt == 1){
            return 0;
        }
        if(cnt == 2){
            cout << "2";
            int x = v[0],y = v[1];
            cout << x << " " << y << endl;
            if(A[x] == B[y] && A[y] == B[x]) return 1;
            else return 0;
        }
        return 0;
    }
};