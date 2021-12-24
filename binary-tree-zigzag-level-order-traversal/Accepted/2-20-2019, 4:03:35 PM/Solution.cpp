// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<int> v[100000];
    int ma = 0;
    void dfs(TreeNode* root, int depth){
        if(root == NULL)
            return ;
        v[depth].push_back(root->val);
        ma = max(ma,depth);
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        int si = 1;
        dfs(root,0);
        
//         vector<int> temp;
//         for(int j=0;j<=ma;j++){
//             if(si == 1){
//                 for(int i=0;i<v[j].size();i++)
//                     temp.push_back(v[j][i]);
//                 si = -1;
//             }
//             else{
//                 for(int i=v[j].size()-1 ;i>=0;i--)
//                     temp.push_back(v[j][i]);
//                 si = 1;
//             }
//             ans.push_back(temp);
//             temp.clear();
//         }
        
         for(int i=0;i<=ma;i++){
             if(i & 1)
                reverse(v[i].begin(),v[i].end());
        }
        for(int i=0;i<=ma;i++){
             ans.push_back(v[i]);
        }
        return ans;
        
            
    }
};