// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int N = 1e6;
    vector<int> par,size;
    int find(int v){
        return (par[v] == v ? v : par[v] = find(par[v]));
    }
    void merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return ;
        par[b] = a;
        size[a] += size[b];
    }
    int longestConsecutive(vector<int>& nums) {
        par.assign(N,0);
        size.assign(N,1);
        for(int i = 0;i<N;i++){
            par[i] = i;
        }
        unordered_map<int,int>m1;
        for(int c : nums){
            m1[c] = 1;
        }
        for(int c : nums){
            if(m1.find(c+1)!= m1.end()){
                merge(c,c+1);
            }
            if(m1.find(c-1)!= m1.end()){
                merge(c,c-1);
            }
        }
        int s = 0;
        for(int c : nums){
            s = max(0,size[find(c)]);
        }
        return s;
    }
};