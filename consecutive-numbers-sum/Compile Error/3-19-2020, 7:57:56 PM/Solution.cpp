// https://leetcode.com/problems/consecutive-numbers-sum

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        vector<long long int> all;
        for(int i =1;i<=12345;i++){
            all.push_back((long long int)i*(i+1)/2);
        }
        int ans =1 ;
        for(int i =1;i<=12;i++){
            cout << N << " " << all[i] <<" "<< N-all[i] <<endl
            if((N-all[i] >= 0 )&& (N-all[i])%i == 0){
                cout << N << " " << all[i] <<" "<< N-all[i] <<endl;
                ans +=1;
            }
        }
        return ans;
    }
};