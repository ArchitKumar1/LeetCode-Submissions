// https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions

class Solution {
public:
    int minCharacters(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        
        int A,B,C;
        
        // all in b less than a;
        {
            char beg = a[0];

            auto it = lower_bound(b.begin(),b.end(),beg);
            if(it == b.begin()){
                A = b.size();
            }else{
                A = b.end() - it;
            }
        }
        
        // all in a less than b;
        {
            char beg = b[0];

            auto it = lower_bound(a.begin(),a.end(),beg);
            if(it == a.begin()){
                B = a.size();
            }else{
                B = a.end() - it;
            }
        }
        vector<int> cnt(26,0);
        for(int c : a) cnt[c-'a']++;
        for(int c : b) cnt[c-'a']++;
        int total = a.size() + b.size();
        
        C = INT_MAX;
        for(int c  : cnt){
            C = min(C,total - cnt[c] );
        }
        cout << A << " " << B << "  " << C << endl;
        return min({A,B,C});
    }
};