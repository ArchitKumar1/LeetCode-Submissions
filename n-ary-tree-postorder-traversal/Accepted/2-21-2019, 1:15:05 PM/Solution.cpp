// https://leetcode.com/problems/n-ary-tree-postorder-traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> ans;
    void dfs(Node*  root){
        
        for(auto c : root->children)
            dfs(c);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(root == NULL) return ans;
        dfs(root);
        return ans;
    }
};