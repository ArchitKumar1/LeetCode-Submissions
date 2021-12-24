// https://leetcode.com/problems/find-largest-value-in-each-tree-row

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
    vector<int> largestValues(TreeNode* root) {
    
        vector<int> ans(1100,INT_MIN);
        vector<int> vis(1000,0);
        
        stack<pair<int,TreeNode*>>st;
        st.push({0,root});
        
        while(st.size()){
            
            auto[d,curr] = st.top();st.pop();
            if(curr == NULL) continue;
            ans[d] = max((int)ans[d],curr->val);
            vis[d] =1;
            st.push({d+1,curr->left});
            st.push({d+1,curr->right});
            
        }
        int pos = 0;
        for(;pos<ans.size();pos++){
            if(vis[pos] == 0)break;
        }
        ans.resize(pos);
        return ans;
        
    }
};