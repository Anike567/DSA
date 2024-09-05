// simple approach is just store the inorder traversal into vector space will be O(N)

//optimize approach is use stack and go to the extreme left as we do in the inorder  
//return the top value of stack  if(st.top.right)  then also go to the extreme left of the stack and store that to stack


class BSTIterator {
private:
   stack<TreeNode*>st;
public:
    
    BSTIterator(TreeNode* root) {
        while( root != nullptr){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();

        if(node->right){
            TreeNode *temp = node->right;
            while( temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
