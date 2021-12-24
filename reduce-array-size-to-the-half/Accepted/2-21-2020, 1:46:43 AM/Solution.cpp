// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int req = arr.size()/2;
        map<int,int> m1;
        for(int c : arr){
            m1[c] +=1;
        }
        vector<pair<int,int>> all;
        for(auto x: m1){
            if(x.second>=1){
                all.emplace_back(x.second,x.first);
            }
        }
        sort(all.rbegin(),all.rend());
        int n = all.size();
        for(int i = 0;i<n;i++){
            if(i>0){
                all[i].first += all[i-1].first;
            }
        }
        int ans = 0;
        int l= 0 ;
        int h = n;
        while(l<=h){
            int mid = (l+h)/2;
            if(all[mid].first >= req){
                ans = mid+1;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};