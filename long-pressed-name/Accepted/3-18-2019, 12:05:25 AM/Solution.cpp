// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<int,int>> a,b;
        int i =0;
        while(i<=name.size()-1){
            char x = name[i];
            int cnt = 0;
            while(i<=name.size()-1 && name[i] == x){
                cnt++;
                i++;
            }
            a.push_back({cnt,x -'a'});
        }
        i = 0;
        while(i<=typed.size()-1){
            char x = typed[i];
            int cnt = 0;
            while(i<=typed.size()-1 && typed[i] == x){
                cnt++;
                i++;
            }
            b.push_back({cnt,x-'a'});
        }
        if(a.size()!=b.size())
            return false;
        for(int i=0;i<b.size();i++){
            if(a[i].second!=b[i].second)
                return false;
            if(a[i].first>b[i].first)
                return false;
        }
        return true;
    }
};