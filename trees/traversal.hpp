#include <bits/stdc++.h>
using namespace std;

 
//--> Iterative

//preOrder => usual stack dfs with right pushed first. (left will be above it)

//postOrder 
//1. Using 1 stack


// 2. Using 2 stacks

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
};

vector<TreeNode*> postOrderTraversal (TreeNode* root) {
  vector<TreeNode*> postOrder;
  if (root == NULL) return postOrder;
  stack<TreeNode*> st1, st2;
  st1.push(root);

  while (!st1.empty()) {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if (root->left) 
      st1.push(root->left);
    if (root->right)
      st1.push(root->right);
  }

  while (!st2.empty()){
    postOrder.push_back(st2.top());
    st2.pop();
  }

  return std::move(postOrder);
}

vector<int> inOrderIt (Node* root) {
  stack<Node*> s;
  Node* node = root;
  vector<int> inOrder;

  while (!s.empty()) {
    if (node)  {
      s.push(node);
      node  = node->left;
    }

    else {
      node = s.top();
      s.pop();

      inOrder.push_back(node);
      node = node->right;
    }
  }

  return inOrder;
}


// -->Recursive

//root -> left -> right
void preOrder (Node* node)  {
  if (node == null)
    return;

  cout<<node->val;

  preOrder (node->left);
  preOrder (node->right);

}


//left -> right -> root
void postOrder (Node* node) {
  if (node == null) 
  return;


  postOrder (node>left);
  postOrder (node->right);
  cout<<node->val;

}

//left -> root -> right 
void inOrder (Node* node) {
  if (node == null)
    return;

  inOrder (node->left);
  cout<<node->val;
  inOrder (node->right);

}



