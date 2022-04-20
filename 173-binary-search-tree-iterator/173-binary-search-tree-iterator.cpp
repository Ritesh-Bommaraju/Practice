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
// class BSTIterator {
// public:
    
//     vector<int> nums;
//     int ptr; 
    
//     void inorder(TreeNode* root){
//         if(root==NULL) return ;
//         inorder(root->left);
//         nums.push_back(root->val);
//         inorder(root->right);
        
//     }
    
//     BSTIterator(TreeNode* root) {
//       inorder(root);  
//       ptr=0;
//     }
    
//     int next() {
//         return nums[ptr++];
//     }
    
//     bool hasNext() {
//          return nums.size()>ptr;
//     }
// };
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top(); // take top element
        myStack.pop(); // pop it out
        pushAll(tmpNode->right); // if has a right, call pushall ...
        return tmpNode->val; // return the top value
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */