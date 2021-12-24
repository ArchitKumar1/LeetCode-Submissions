// https://leetcode.com/problems/maximum-xor-with-an-element-from-array

class Solution {
public:
    
    struct node{
        node* next[2];
    };
    struct query{
        int x,m,idx;
    };
    vector<query> Q;
    void add(node* root, int x){
        for(int i = 31;i>=0;i--){
            int bit = x>>i&1;
            if(!root->next[bit]){
                root->next[bit] = new node();
            }
            root = root->next[bit];
        }
    }
    int solve(node* root,int x){
        int ans = 0;
        for(int i = 31;i>=0;i--){
            int bit = x>>i&1;
            if(root->next[bit^1]){
                root = root->next[bit^1];
                ans|=(1<<i);
            }else{
                if(root->next[bit]){
                    root = root->next[bit];
                }else{
                    break;
                }
            }
        }
        return ans;
    }
    node *root;
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(),M = queries.size();
        Q.resize(M);
        for(int i = 0;i<M;i++){
            Q[i].x = queries[i][0],Q[i].m = queries[i][1];Q[i].idx = i;
        }
        sort(nums.begin(),nums.end());
        sort(Q.begin(),Q.end(),[&](query a,query b){return a.m < b.m;});

        vector<int> ans(M);
        root = new node();
        for(int j = 0, i =0;j<M;j++){
            while(i < N && nums[i] <= Q[j].m){
                add(root,nums[i++]);
            }
            ans[Q[j].idx] = i>0?solve(root,Q[j].x):-1;
        }
        return ans;
    }
};