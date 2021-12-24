// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

class Solution {
public:
    struct node{
        node* next[2];
    };
    
    void add(int x,node* root){
        
        for(int i = 31;i>=0;i--){
            int bit = ((1<<i)&x)>=1;
            if(!(root->next[bit])){
                root->next[bit] = new node();
            }
            root = root->next[bit];
        }
    }
    int get(int x,node* root){
        int ans = 0;
        for(int i = 31;i>=0;i--){
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
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int fans = 0;
        node* root = new node();
        for(int i = 0;i<n;i++){
            add(nums[i],root);
        }
        for(int i = 0;i<n;i++){
            fans = max(fans,get(nums[i],root));
        }
        return fans;
        
    }
};