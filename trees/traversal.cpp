#include <queue>   // std::queue
#include <stack>   // std::std::stack
#include <vector>  // std::std::vector

struct Node {
  Node* left;
  Node* right;
};

std::vector<Node*> traversal;

/* PRE-ORDER
 * Root -> Left -> Right
 *
 * @brief keep marking and going left while adding to the stack the right nodes.
 * If can't go left anymore use the stack to get the most recent right.
 */
void PreOrderItervative(Node* root) {
  if (root == nullptr) return;
  std::stack<Node*> st;
  Node* cur = root;

  while (cur != nullptr || !st.empty()) {
    traversal.push_back(cur);
    if (cur->right != nullptr) st.push(cur->right);
    if (cur->left != nullptr)
      cur = cur->left;
    else {
      cur = st.top();
      st.pop();
    }
  }
}

void PreOrderRecursive(Node* root) {
  if (root == nullptr) return;
  traversal.push_back(root);
  PreOrderItervative(root->left);
  PreOrderItervative(root->right);
}

/* POST-ORDER
 * Left -> Right -> Root
 *
 * @brief use cur == nullptr to switch between traversing left and right sides.
 * remember the last node to decide going right
 */
void PostOrderIterative(Node* root) {
  if (root == nullptr) return;
  std::stack<Node*> st;
  Node* cur = root;
  Node* last;
  while (cur != nullptr || !st.empty()) {
    if (cur != nullptr) {
      st.push(cur);
      cur = cur->left;
    } else {
      Node* peek = st.top();
      if (peek->right != nullptr && last != peek->right)
        cur = peek->right;
      else {
        traversal.push_back(peek);
        last = st.top();
        st.pop();
      }
    }
  }
}

/*
 * @brief use cur == nullptr to switch between traversing left and right sides.
 * Repush root after finsihing left side to come back to it later.
 */
void PostOrderIterative_comprehensive(Node* root) {
  if (root == nullptr) return;
  std::stack<Node*> st;

  Node* cur = root;
  while (cur != nullptr || !st.empty()) {
    while (cur != nullptr) {
      if (cur->right != nullptr) st.push(cur->right);
      st.push(cur);
      cur = cur->left;
    }

    cur = st.top();
    st.pop();
    if (!st.empty() && root->right != nullptr && st.top() == cur->right) {
      st.pop();
      st.push(cur);
      cur = cur->right;
    } else {
      traversal.push_back(cur);
      cur = nullptr;
    }
  }
}

void PostOrderRecursive(Node* root) {
  if (root == nullptr) return;
  PostOrderRecursive(root->left);
  PostOrderRecursive(root->right);
  traversal.push_back(root);
}

/* IN-ORDER
 * Left -> Root -> Right
 */
void InorderIterative(Node* root) {
  std::vector<Node*> traversal;
  std::stack<Node*> st;
  Node* cur = root;
  while (cur != nullptr || st.empty()) {
    while (cur) {
      st.push(cur->left);
      cur = cur->left;
    }
    cur = st.top();
    st.pop();
    traversal.push_back(cur);
    cur = cur->right;
  }
}

void InorderRecursive(Node* root) {
  if (root == nullptr) return;
  InorderRecursive(root->left);
  traversal.push_back(root);
  InorderRecursive(root->right);
}

/*
 * LEVEL-ORDER
 * Level by level.
 */
void LevelOrderIterative(Node* root) {
  std::queue<Node*> q;
  q.push(root);
  int n;
  Node* cur;
  while (!q.empty()) {
    n = q.size();
    for (int i = 0; i < n; i++) {
      cur = q.front();
      traversal.push_back(cur);
      q.pop();
      if (cur->left != nullptr) q.push(cur->left);
      if (cur->right != nullptr) q.push(cur->right);
    }
  }
}
