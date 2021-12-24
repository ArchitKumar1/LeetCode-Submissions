// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> s1;
        int A[100]={0};
        for(auto c: s){
            A[c-'a']++;
        }
        for(int i=0;i<100;i++){
            if(A[i]){
                s1.push({A[i],'a'+ i});
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