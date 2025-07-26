/**
 * src: https://cp-algorithms.com/graph/lca_binary_lifting.html
 * BINARY LIFTING find the lowest common ancestor of two nodes in a tree.
 *  -> ancestor: node that lies on the path connecting the current node to the
 * root node.
 * TIME COMPLEXITY:
 *        -> PREPROCESSING: O(m_N logm_N)
 *        -> ALGORITHM: O(logm_N)
 *
 *  PREPROCESSING:
 *  1. precompute 2^kth ancestor above each node.
 *     - use dfs and dp with the relation 2^ith ancestor = 2^(i-1th) ancestor of
 * 2^(i-1th) ancestor. (2 * 2^(i-i))
 *
 *  2. record the subtree dfs starting time and ending time for each node. use
 * it to determine if two nodes are ancestors.
 *
 *  ALGORITHM:
 *  0. if either nodes is already an acestor of each other return the ancestor.
 *  1. probe one of the given nodes (say u) to find the ancestor:
 *    1.1 starting from the highest jump from u decrease down till we reach
 * somewhere that is not an ancestor of v.
 *    2.2 reassign our probing node and continue.
 *
 *  3. after we can no longer make a jump that confines us below an ancestor to
 * v, our LCA must be the parent of our probing node.
 *
 *  ...
 *   -> tin and tout times of node u lie between the tin and tou times of node v
 * if u belongs to v's subtree. hence concluding v as it's ancestor.
 */
#pragma once
#include <cmath>   // log2, ceil
#include <vector>  // std::vector

class BinLifting {
 public:
  BinLifting(const std::vector<std::vector<int>>& adj, int N) : m_adj{adj}, m_N{N} {}

  int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;

    for (int i = m_L; i >= 0; --i) {
      if (!isAncestor(m_up[u][i], v)) u = m_up[u][i];
    }

    return m_up[u][0];
  }

  bool isAncestor(int u, int v) {
    return m_tin[u] <= m_tin[v] && m_tout[u] >= m_tout[v];
  }

  void preprocess(int root) {
    m_tin.resize(m_N);
    m_tout.resize(m_N);
    m_timer = 0;
    m_L = ceil(log2(m_N));
    m_up.assign(m_N, std::vector<int>(m_L + 1));
    dfs(root, root);
  }

 private:
  void dfs(int node, int parent) {
    m_tin[node] = ++m_timer;
    m_up[node][0] = parent;

    for (int i = 1; i <= m_L; ++i)
      m_up[node][i] = m_up[m_up[node][i - 1]][i - 1];

    for (int u : m_adj[node]) {
      if (u != parent) dfs(u, node);
    }
    m_tout[node] = ++m_timer;
  }

  const std::vector<std::vector<int>>& m_adj;
  std::vector<std::vector<int>> m_up;
  std::vector<int> m_tin, m_tout;
  int m_N;
  int m_L;
  int m_timer;
};

// #include <iostream>
// int main() {
//   std::cout << "compiled\n";
//   return 0;
// }
