vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};
    
    stack<TreeNode*> st;
    st.push(root);
    vector<int> ans;
    
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        
        ans.push_back(node->val);
        
        // First push left, then right (reversed order of postorder)
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }

    // Reverse the result to get postorder (left-right-root)
    reverse(ans.begin(), ans.end());
    return ans;
}
