// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    
public:
    vector<pair<int,int>> vec[2500];
    
    void dfs(TreeNode* root,int side,int depth){
        if(root == NULL)return ;
        vec[side].push_back({depth,root->val});
        dfs(root->left ,side-1,depth+1);
        dfs(root->right,side+1,depth+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,1200,0);
        vector<vector<int>> ans;
        vector<int>temp;
        for(int i=0;i<2500;i++){
            if(vec[i].size() == 0) continue;
            else{
                sort(vec[i].begin(),vec[i].end());
                for(pair<int,int> p : vec[i]){
                    temp.push_back(p.second);
                }
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};