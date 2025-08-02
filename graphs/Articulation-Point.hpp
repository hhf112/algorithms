/**
 * ARTICULATION POINT
 * -> used to find vertices in graph on removal of which the graph is divided
 * into multiple parts
 */

#include <bits/stdc++.h>
using namespace std;

class Articulation {
  // --> same as tarjan
  //  --> slight condition change
  //      -> low[it] >= tim[node]
  //
  //  -->separte consideration for the start of the graph

 public:
  vector<int> findArticulation(int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0), tim(n), low(n), mark(n, 0);
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs(i, -1, tim, low, vis, mark, adj);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (mark[i] == 1) ans.push_back(i);
    }

    if (!ans.size()) return {-1};
    return ans;
  }

 private:
  void dfs(int node, int parent, vector<int>& tim, vector<int>& low,
           vector<int>& vis, vector<int>& mark, vector<vector<int>>& adj) {
    vis[node] = 1;
    tim[node] = low[node] = m_timer;
    m_timer++;
    int child = 0;
    for (auto& it : adj[node]) {
      if (it == parent) continue;
      if (!vis[it]) {
        dfs(it, node, vis, tim, low, mark, adj);
        low[node] = min(low[node], low[it]);
        if (low[it] >= tim[node] && parent != -1) mark[it] = 1;
        child++;
      } else {
        low[node] = min(low[node], tim[it]);
      }
      if (child > 1 && parent == -1) mark[node] = 1;
    }
  }
  int m_timer = 0;
};
