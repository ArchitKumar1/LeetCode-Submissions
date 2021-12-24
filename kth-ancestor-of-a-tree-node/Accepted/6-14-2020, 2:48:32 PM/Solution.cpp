// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

class TreeAncestor {
    
private : 
    const static int LOGN = 20;
    
public:
    int n;
    vector<vector<int>> anc;
    vector<vector<int>> G;
    vector<int> depth;
    
    void dfs(int s){
        for(int c : G[s]){
            depth[c] = depth[s] + 1;
            anc[0][c] = s;
            dfs(c);
        }
    }
    TreeAncestor(int n, vector<int>& parent) {
        depth.assign(n,0);
        G.resize(n);
        anc =vector<vector<int>>(LOGN,vector<int>(n,0));
        this->n = n;
        
        // cout << "mila" << endl;
        for(int i = 0;i<n;i++){
            if(parent[i]!=-1){
                G[parent[i]].push_back(i);
            }
        }
        dfs(0);
        for(int i = 1;i<LOGN;i++){
            for(int j = 0;j<n;j++){
                anc[i][j] = anc[i-1][anc[i-1][j]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans = node;
        if(depth[node] - k <  0) return -1;
        // return 1;
        int newdepth = depth[node] - k;
        for(int i = LOGN-1;~i;i--){
            if(depth[anc[i][ans]] >= newdepth){
                ans = anc[i][ans];
            }
        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */