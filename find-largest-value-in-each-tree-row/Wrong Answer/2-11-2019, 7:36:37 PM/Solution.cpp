// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> v1;
    int arr[10000];
    void dfs(TreeNode* root,int sum){
        
        if(root==NULL) return ;
        sum=sum+1;
        arr[sum-1]=max(arr[sum-1],root->val);
        dfs(root->right,sum);
        dfs(root->left,sum);
    }
    vector<int> largestValues(TreeNode* root) {
        memset(arr,-10,sizeof(arr));
        dfs(root,0);
        for(int i=0;i<10000;i++){
            if(arr[i]!=-10)
                v1.push_back(arr[i]);
        }
        return v1;
    }
};