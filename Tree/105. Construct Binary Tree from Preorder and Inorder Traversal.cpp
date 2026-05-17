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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> in_map;

        for(int i=0; i<inorder.size(); i++){
            in_map[inorder[i]] = i;
        }

        int pre_end = preorder.size() - 1;
        int in_end = inorder.size() - 1;


        TreeNode* root = createTreeFromInorderAndPreorder(preorder, 0, pre_end,
                                                         inorder, 0, in_end, in_map);
        
        return root;
    }

    TreeNode* createTreeFromInorderAndPreorder(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end, map<int, int> &in_map){
        
        if (pre_start > pre_end || in_start > in_end){
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[pre_start]);

        int node_index_in_inorder = in_map[node->val];
        int left_nodes_size = node_index_in_inorder - in_start;

        node->left = createTreeFromInorderAndPreorder(preorder, pre_start + 1, pre_start + left_nodes_size,
                                                    inorder, in_start, in_start + left_nodes_size, in_map);

        node->right = createTreeFromInorderAndPreorder(preorder, pre_start + left_nodes_size + 1, pre_end,
                                                    inorder, node_index_in_inorder + 1, in_end, in_map);
        
        return node;
    }
};