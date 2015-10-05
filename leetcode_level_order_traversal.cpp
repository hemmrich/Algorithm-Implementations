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
vector<vector<int>> levelOrder(TreeNode* root) {
        
    vector<vector<int>> solution;
       
    if(!root)
        return solution;
        
    solution.push_back({});
       
    queue<TreeNode*> cur_level;
    queue<TreeNode*> next_level;
    int level = 0;
       
    cur_level.push(root);
     
    while(!cur_level.empty()) {
        TreeNode* cur = cur_level.front();
        cur_level.pop();
           
        if(cur) {
            solution[level].push_back(cur->val);
            cout << "Visited " << cur->val << endl;
                
            if(cur->left)
                next_level.push(cur->left);
            if(cur->right)
                next_level.push(cur->right);
                
            if(cur_level.empty()) {
                cout << "visited all nodes in level " << level << endl;
                level++;
                  
                if(!next_level.empty())
                    solution.push_back({});
                       
                swap(cur_level, next_level);
            }
        }
    }
    return solution;
}
};
