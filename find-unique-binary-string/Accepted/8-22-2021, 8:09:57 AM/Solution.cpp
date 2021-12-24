// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    string bin(int num){
        string s;
        while(num){
            
            if(num&1)s+= '1';
            else s+= '0';
            num/=2;
            
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        const int n = nums[0].size();
        map<string,int> m1;
        for(auto x : nums) m1[x]++;
        for(int i = 0;i < 1 << n;i++){
            
            string s = bin(i);
            cout << s << endl;
            int l = n - s.size();
            string p = "";
            while(l--) p += '0';
            s = p + s;
            cout << i << " " << s << " : " << endl;
            if(!m1[s]) return s;
        }
        return "";
    }
};