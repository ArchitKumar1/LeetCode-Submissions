// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        multiset<int> s;
        for(int x : nums){
            s.insert(x);
        }
        int ans = INT_MAX;

        
        for(int i = 0;i<n;i++){
            int MA = *prev(s.end());
            int MI = *s.begin();
            int A1 ,A2;
            {
                s.insert(MA/2);
                s.erase(s.find(MA));
                {
                    int MA = *prev(s.end());
                    int MI = *s.begin();
                    A1 = abs(MA-MI);
                }
                s.insert(MA);
                s.erase(s.find(MA/2));
            }
            {
                s.insert(2*MI);
                s.erase(s.find(MI));
                {
                    int MA = *prev(s.end());
                    int MI = *s.begin();
                    A2 = abs(MA-MI);
                }
                s.insert(MI);
                s.erase(s.find(2*MI));
            }
            cout << i << " " << A1 << " " << A2 << endl;
            if(A1 < A2){
                s.insert(MA/2);
                s.erase(s.find(MA));
            }else{
                s.insert(2*MI);
                s.erase(s.find(MI));
            }
            for(int x : nums){
                cout << x << " ";
            }
            cout << endl;
            int A = min(A1,A2);
            if(A < ans){
                ans = A;
            }else{
                break;
            }
            
        }
        return ans;
        
    }
};