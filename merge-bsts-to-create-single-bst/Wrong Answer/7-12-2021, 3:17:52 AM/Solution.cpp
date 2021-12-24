// https://leetcode.com/problems/merge-bsts-to-create-single-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool safe = 1;
    void dfs(TreeNode* node,int &mini){
        
        if(!node) return;
        cout << node->val << endl;
        dfs(node->left,mini);
        if(node->val > mini){
            mini = node->val;
        }else{
            safe = false;
        }
        dfs(node->right,mini);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
         map<int,vector<TreeNode*>> m1;
        
        for(auto x : trees){
            m1[x->val].push_back(x);
        }
        for(auto x : trees){
            //cout << x->val << endl;
            auto l = x->left;
            auto r = x->right;
            if(l){
                if(!m1[l->val].size()) continue;
                auto pt = m1[l->val].back();
                x->left = pt;
                m1[l->val].pop_back();
            }
            if(r){
                if(!m1[r->val].size())  continue;
                auto pt = m1[r->val].back();
                x->right = pt;
                m1[r->val].pop_back();
            }
        }
        
        // check if 1 parent is left
        vector<TreeNode*> lefts;
        for(auto x : m1){
            for(auto node : x.second){
                lefts.push_back(node);
            }
        }
        // cout << "all" << endl;
        if(lefts.size() != 1) return NULL;
        int mini = INT_MIN;
        dfs(lefts[0],mini);
        return safe ? lefts[0] : NULL;
        
    }
};