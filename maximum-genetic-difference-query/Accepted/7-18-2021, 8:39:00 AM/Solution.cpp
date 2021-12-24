// https://leetcode.com/problems/maximum-genetic-difference-query

class Solution {
public:
    vector<vector<int>> G;
    vector<vector<pair<int,int>>> Q;
    vector<int> ans;
    struct node{
        node* next[2];
        int cnt = 0;
    };
    node *root;
    
    void add(int x,node* root){
        
        for(int i = 18;i>=0;i--){
            int bit = ((1<<i)&x)>=1;
            if(!(root->next[bit])){
                root->next[bit] = new node();
            }
            root = root->next[bit];
            root->cnt++;
        }
    }
    void remove(int x,node* root){
        
        for(int i = 18;i>=0;i--){
            int bit = ((1<<i)&x)>=1;
            assert(root->next[bit]);
            node* next = root->next[bit];
            if(next->cnt == 1){
                root->next[bit] = NULL;
                break;
            }else{
                root = next;
                root->cnt--;
            }
        }
    }
    int get(int x,node* root){
        int ans = 0;
        for(int i = 18;i>=0;i--){
            int bit = ((1<<i)&x)>=1;
            if(!root->next[bit^1]){
                if(!root->next[bit]){
                    return ans;
                }else{
                    root = root->next[bit];
                }
            }else{
                ans += (1<<i);
                root = root->next[bit ^ 1];
            }
        }
        return ans;
    }
    
    void dfs(int s,int par){
        //add 
        add(s,root);
        for(auto [val,idx] : Q[s]){
            int mx = get(val,root);
            ans[idx] = mx;
        }
        for(int c : G[s]){
            if(c == par) continue;
            dfs(c,s);
        }
        
        //remove
        remove(s,root);
        
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        int n = parents.size();
        // make tree
        G.resize(n+1);
        Q.resize(n+1);
        int rooto = -1;
        for(int i =0 ;i < n;i++){
            if(parents[i] == -1) {
                rooto = i;
                continue;
            }
            G[i].push_back(parents[i]);
            G[parents[i]].push_back(i);
        }
        
        int q = queries.size();
        ans.resize(q);
        
        int pos = 0;
        for(auto query : queries){
            int node = query[0];
            int val = query[1];
            Q[node].emplace_back(val,pos++);
        }
        
        root = new node();
        dfs(rooto,rooto);
    
        
        return ans;
    }
};