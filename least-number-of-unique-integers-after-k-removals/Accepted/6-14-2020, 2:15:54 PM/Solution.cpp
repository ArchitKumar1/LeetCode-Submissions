// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m1;
        for(int c : arr) m1[c]++;
        vector<int> v;
        for(auto x : m1){
            if(x.second > 0){
                cout << x.first << " " << x.second << endl;
                v.push_back(x.second);
            }
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int c : v){
            cout << c << " " << k << endl;
            if(k-c >=0){
                cnt +=1;
                k-=c;
            }else{
                break;
            }
        }
        return v.size() - cnt;
        
    }
};