// https://leetcode.com/problems/maximum-number-of-removable-characters

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size();
        int m = p.size();
        int o = removable.size();
        
        int l = 0,h = o;
        int ans = 0;
        while(l<=h){
            int mid = (l+h)/2;
            string t;
            set<int> st;
            for(int i = 0;i < mid;i++){
                st.insert(removable[i]);
            }
            for(int i = 0,j = 0;i<n;i++){
                if(st.find(i)==st.end()){
                    t += s[i];
                }
            }
            //cout << mid << " "<< t << endl;
            int j = 0;
            for(int i = 0;i < t.size();i++){
                if(t[i] == p[j]) j++;
            }
            //cout << j << " " << m << endl;
            if(j == m){
                ans = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
};