// https://leetcode.com/problems/maximum-genetic-difference-query

struct XOR_binary_trie{
    // Trie implementation of maximum xor query in a list of values
    struct node{
        node* next[2];
        int cnt = 0;
    };
    node *R;
    XOR_binary_trie(){
        R = new node();
    }
    int MAX_BIT = 18;
    void add(int x,int count = 1){
        node* root = R;
        for(int i = MAX_BIT;i>=0;i--){
            int bit = x>>i&1;
            if(!(root->next[bit])){
                root->next[bit] = new node();
            }
            root = root->next[bit];
            root->cnt++;
        }
    }
    // removes count occurence of the number from the trie
    void remove(int x,int count = 1){
        node* root = R;
        for(int i = MAX_BIT;i>=0;i--){
            int bit = ((1<<i)&x)>=1;
            assert(root->next[bit]);
            node* next = root->next[bit];
            if(next->cnt == count){
                root->next[bit] = NULL;
                break;
            }else{
                root = next;
                root->cnt -= count;
            }
        }
    }
    int get(int x){
        node* root = R;
        int ans = 0;
        for(int i = MAX_BIT;i>=0;i--){
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
};

class Solution {
public:
    vector<vector<int>> G;
    vector<vector<pair<int,int>>> Q;
    vector<int> ans;
   
    XOR_binary_trie *trie;
    void dfs(int s,int par){
        //add 
        trie->add(s);
        for(auto [val,idx] : Q[s]){
            int mx = trie->get(val);
            ans[idx] = mx;
        }
        for(int c : G[s]){
            if(c == par) continue;
            dfs(c,s);
        }
        
        //remove
        trie->remove(s);
        
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
        
        trie = new XOR_binary_trie();
        int q = queries.size();
        ans.resize(q);
        
        int pos = 0;
        for(auto query : queries){
            int node = query[0];
            int val = query[1];
            Q[node].emplace_back(val,pos++);
        }
        
        dfs(rooto,rooto);
    
        
        return ans;
    }
};