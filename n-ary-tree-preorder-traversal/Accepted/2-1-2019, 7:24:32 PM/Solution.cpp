// https://leetcode.com/problems/n-ary-tree-preorder-traversal

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
    vector<int> trav;
    void dfs(Node* root){
        if(root==NULL) return;
        trav.push_back(root->val);
        for(auto i =0;i<root->children.size();i++){
            dfs(root->children[i]);
        }
    }
    vector<int> preorder(Node* root) {
        dfs(root);
        return trav;
    }
};