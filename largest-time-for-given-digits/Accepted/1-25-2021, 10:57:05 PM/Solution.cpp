// https://leetcode.com/problems/largest-time-for-given-digits

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        
        string s;
        for(int c : arr){
            s += '0'+c;
        }
        
        auto safe = [&](string s){
            string H = s.substr(0,2);
            string M = s.substr(2,2);
            
            return stoi(H)<=23 && stoi(M)<=59;
        };
        
        string ans;
        sort(s.begin(),s.end());
        cout <<s <<endl;
        
        do{
            if(safe(s)) ans = max(ans,s);
        }while(next_permutation(s.begin(),s.end()));
        
        return ans==""?ans:ans.substr(0,2)+ ":" + ans.substr(2,2);
    }
};