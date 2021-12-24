// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums){
            sum +=x;
        }
        vector<int> ones,twoes;
        for(int x :nums){
            if(x%3 == 0) continue;
            else if(x%3 ==1)ones.push_back(x);
            else twoes.push_back(x);
        }
        sort(ones.begin(),ones.end());
        sort(twoes.begin(),twoes.end());
        
        vector<int>all;
        
        int cntones = ones.size()%3;
        int cnttwoes = twoes.size()%3;
        
        for(int i = 0;i<cntones;i++){
            cout << ones[i] << " ";
            all.push_back(ones[i]);
        }
        for(int i = 0;i<cnttwoes;i++){
            cout << twoes[i] << " ";
            all.push_back(twoes[i]);
        }
        for(int x : all){
            sum -=x;
        }
        int m = all.size();
        
        int mask = (1 << m);
        int fans = 0;

        for(int i=0;i<mask;i++){
            int temp = 0;
            for(int j=0;j<20;j++){
                if((1<<j)&i){
                    temp += all[j];
                }
            }
            if(temp%3 == 0)fans = max(fans,temp);
        }
        sum +=fans;
        return sum;
        

    }
};