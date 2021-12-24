// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> s1;
        int A[500]={0};
        for(auto c: s){
            A[c]++;
        }
        for(int i=0;i<500;i++){
            if(A[i]){
                s1.push({A[i],i});
            }
        }
        string ans = "";
        while(!s1.empty()){
            pair<int,char> c = s1.top();
            s1.pop();
            int x = c.first;
            char y = c.second;
            while(x--){
                ans +=y;
            }
        }
        return ans;
    }
};