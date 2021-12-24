// https://leetcode.com/problems/closest-divisors

class Solution {
public:
    vector<int> fact(int n){
        vector<int> ans;
        for(int i = 1;i*i<=n;i++){
            if(n%i == 0){
                ans.push_back(i);
                ans.push_back(n/i);
            }   
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    vector<int> closestDivisors(int num) {
        pair<int,int> f;
        vector<int> f1;
        vector<int> f2;
        int n = num+1;
        int m = num+2;
        f1 = fact(n);
        f2 = fact(m);
        for(int c : f1){
            cout << c << " ";
        }
        cout << endl;
        
        for(int c : f2){
            cout << c << " ";
        }
        cout << endl;
        int diff = INT_MAX;
        n = f1.size();
        for(int i = 0;i<n/2;i++){
            if(f1[n-i-1] - f1[i] < diff){
                diff = f1[n-i-1] - f1[i];
                f.first = f1[i];
                f.second = f1[n-i-1];
            }
        }
        f2 = f1;
         n = f1.size();
        for(int i = 0;i<n/2;i++){
            if(f1[n-i-1] - f1[i] < diff){
                diff = f1[n-i-1] - f1[i];
                f.first = f1[i];
                f.second = f1[n-i-1];
            }
        }
        return vector<int>({f.first,f.second});
    }
};