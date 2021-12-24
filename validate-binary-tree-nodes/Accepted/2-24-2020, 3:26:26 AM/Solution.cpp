// https://leetcode.com/problems/validate-binary-tree-nodes

class Solution {
public:
    vector<int> vis;
    bool ok;
    
    void dfs(int s,vector<int>& l, vector<int>& r){
        if(vis[s] == 1){
            ok = 0;
            cout << "muddasir";
            return;
        }
        vis[s] = 1;
        if(l[s] !=-1)dfs(l[s],l,r);
        if(r[s] !=-1)dfs(r[s],l,r);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& l, vector<int>& r) {
        vis.assign(n,0);
        ok = 1;
        dfs(0,l,r);
        for(int i = 0;i<n;i++){
            if(vis[i] == 0){
                ok = 0;
            }
        }
        for(int i = 0;i<n;i++){
            cout << i << " " <<vis[i]  << endl;
        }
        return ok;
    }
};