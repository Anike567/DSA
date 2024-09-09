/*

  deserialize Function:

String Splitting: Convert the comma-separated string into a vector of node values.
Edge Case: If the string is empty or the first value is "null", return nullptr.
Deserialization:
Create the root node and initialize a queue for level-order traversal.
For each node, assign left and right children if values are not "null".
Add non-null children to the queue for further processing.
Bounds Checking: Ensure that you check bounds before accessing elements of the vector to avoid out-of-bounds errors.

*/

 TreeNode* deserialize(string data) {
        if (data == "") {
            return nullptr;
        }

   
        vector<string> arr;
        int n = data.size();
        string temp = "";
        for (int i = 0; i < n; i++) {
            if (data[i] == ',') {
                arr.push_back(temp);
                temp = "";
            } 
            else {
                temp += data[i];
            }
        }
        arr.push_back(temp); 

   
        if (arr.empty()) {
            return nullptr;
        }

    
        int idx = 0;
        if (arr[idx] == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(arr[idx++]));
        queue<TreeNode*> q;
        q.push(root);

        while (idx < arr.size() && !q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (idx < arr.size() && arr[idx] != "null") {
                current->left = new TreeNode(stoi(arr[idx]));
                q.push(current->left);
            }
            idx++;

            if (idx < arr.size() && arr[idx] != "null") {
                current->right = new TreeNode(stoi(arr[idx]));
                q.push(current->right);
            }
            idx++;
        }

    return root;
}


/*
  serialize Function:

Level-Order Traversal:
Use a queue to perform a breadth-first traversal of the tree.
For each node, add its value to the result. Add "null" if the node is nullptr.
Enqueue left and right children for further processing.
Trailing Nulls: After the traversal, remove unnecessary trailing "null" values from the result.
String Construction: Join the values from the vector into a comma-separated string.

*/

string serialize(TreeNode* root) {
        vector<string>ans;
        if( root == nullptr){
            return "";
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp == nullptr){
                ans.push_back("null");
            }
            else{
                ans.push_back(to_string(temp->val));
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        int i=ans.size()-1;
        while(i>=0 && ans[i] == "null"){
            ans.pop_back();
            i--;
        }
        string dslrz="";
        int n=ans.size();
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" "<<endl;
            dslrz+=ans[i];
            if( i!=n-1){
                dslrz+=",";
            }
        }
        return dslrz;
        
    }
