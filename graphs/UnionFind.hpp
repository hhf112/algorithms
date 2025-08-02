#pragma once
#include <vector>  // std::vector

class UnionFind {
 public:
  UnionFind(int n) {
    m_size.resize(n + 1, 1);
    m_parent.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
      m_parent[i] = i;
    }
  }

  inline int find(int u) {
    if (u == m_parent[u])
      return u;
    else
      return m_parent[u] = find(m_parent[u]);
  }

  inline bool unite(int u, int v) {
    int up = find(u), vp = find(v);
    if (up == vp) return false;

    if (m_size[up] > m_size[vp]) {
      m_parent[vp] = up;
      m_size[vp] += m_size[vp];
    } else {
      m_parent[up] = vp;
      m_size[up] += m_size[vp];
    }
    return true;
  }

  std::vector<int>& getParents() { return m_parent; }
  std::vector<int>& getSizes() { return m_size; }

 private:
  std::vector<int> m_parent;
  std::vector<int> m_size;
};
