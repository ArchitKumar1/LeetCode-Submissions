// https://leetcode.com/problems/maximum-xor-with-an-element-from-array

class Solution {
public:
    
    struct node{
        node* next[2];
    };
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
        return ans>0?ans:-1;
    }
    node *root;
    int N,M;
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        N = nums.size(); M = queries.size();
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),[&](vector<int> a,vector<int>b){return a[1] < b[1];});

        vector<int> ans;
        root = new node();
        for(int j = 0, i =0;j<M;j++){
            while(i < N && nums[i] <= queries[j][1]){
                add(root,nums[i++]);

            }
            ans.push_back(solve(root,queries[j][0]));
        }
        return ans;
    }
};