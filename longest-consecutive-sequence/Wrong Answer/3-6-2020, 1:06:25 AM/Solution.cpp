// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int offset = 5e6;
    
    unordered_map<long long,int> par,size,m1;
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
    int longestConsecutive(vector<int>& nums2) {
        vector<long long> nums;
        for(int c :nums2){
            // nums.push_back((long long)c + offset);
            nums.push_back((long long)c );
            
        }
        for(int c : nums){
            
            m1[c] = 1;
            par[c] = c;
            size[c] = 1;
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
            cout << find(c) << " " << size[find(c)] << endl; 
        }
        return s;
    }
};