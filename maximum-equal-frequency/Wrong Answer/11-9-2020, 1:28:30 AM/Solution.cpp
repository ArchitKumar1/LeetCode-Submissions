// https://leetcode.com/problems/maximum-equal-frequency


class Solution {

public:
    int maxEqualFreq(vector<int>& nums) {
        map<int,int> m1,m2;
        
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            
            
            int c = nums[i];
            m1[c]++;
            m2[m1[c]]++;
            
            if(m1[c]> 1 ) m2[m1[c]-1]--;
            if(m2[m1[c]-1] == 0){
                m2.erase(m1[c]-1);
            }
            cout << "BEG "<<i<< endl;
            for(auto x : m2){
                cout << x.first <<" "<<x.second << endl;
            }
            cout << "END"<< endl;
            if(m2.size() == 2){
                auto it1 = m2.begin();
                auto it2 = next(m2.begin());
                cout << it1->first<< " "<<it1->second<<" "<<it2->first<<" "<<it2->second<<endl;
                if(it2->first == (it1->first+1) && it1->second == 1){
                    ans = i+1;
                }   
                if(it1->second == 1 || it2->second == 1){
                    ans = i+1;
                }   
            }
            if(m2.size() == 1){
                ans = i+1;
            }
            
        }
        return ans;
    }
};