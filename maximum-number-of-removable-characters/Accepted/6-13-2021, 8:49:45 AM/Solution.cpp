// https://leetcode.com/problems/maximum-number-of-removable-characters

#pragma GCC optimize("Ofast")
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // ios_base::sync_with_stdio(false); cin.tie(NULL);

        int n = s.size();
        int m = p.size();
        int o = removable.size();
        
        int l = 0,h = o-1;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            // unordered_map<int,int> m1;
            // m1.reserve(o+1);
            unordered_set<int> st;
            st.reserve(o+1);
            for(int i = 0;i <= mid;i++){
              //  m1[removable[i]] = 1;
                st.insert(removable[i]);
            }
            //cout << mid << " "<< t << endl;
            int j = 0;
            for(int i = 0;i < s.size();i++){
                //if(m1[i] != 1 && s[i] == p[j]) j++;
                if(st.find(i) == st.end() && s[i] == p[j]) j++;
            }
            //cout << j << " " << m << endl;
            if(j == m){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        if(ans == -1) return 0;
        else return ans+1;
    }
};