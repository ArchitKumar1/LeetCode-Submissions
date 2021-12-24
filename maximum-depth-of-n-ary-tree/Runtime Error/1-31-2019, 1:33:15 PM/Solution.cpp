// https://leetcode.com/problems/maximum-depth-of-n-ary-tree

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
    void dfs(Node* root,int sum,int &msum){
        for(auto i: root->children){
            msum=max(msum,sum+1);
            dfs(i,sum+1,msum);
        }
    }
    int maxDepth(Node* root) {
        int msum=0;
        dfs(root,1,msum);
        return msum;
    }
};