// https://leetcode.com/problems/jump-game-vii


class fenwick{
    public:
    int n;
    vector<int> BIT;
    fenwick(int _n){
        n = _n;
        BIT.assign(n,0);
    }
    void add(int v,int i){
        i++;
        for(;i < n;i+=(i&-i)){
            BIT[i] += v;
        }
    }
    int get(int i){
        i++;
        int ans = 0;
        for(;i > 0;i-=(i&-i)){
            ans += BIT[i];
        }
        return ans;
    }
    int sum(int l,int r){
        return get(r) -get(l-1);
    }
    int value_at(int i){
       return sum(i,i);
    }
};
class Solution {
public:
    
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        fenwick tree(n+1);
        tree.add(1,0);  
        for(int i = 1;i<n;i++){
            if(s[i]!='0') continue;
            int minj = i - minJump;
            int maxj = i - maxJump;
            
            if(minj < 0) continue;
            if(tree.sum(max(0,maxj),minj) > 0){
                tree.add(1,i);
            }
        }
        // for(int i = 0; i < n;i++){
        //     cout << i << " " << tree.value_at(i) << endl;
        // }
        return tree.value_at(n-1) > 0;
    }
};