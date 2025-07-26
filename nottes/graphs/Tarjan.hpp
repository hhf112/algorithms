/**
 * TARJAN'S ALGORITHM: find bridges in graphs.
 * TIME COMPLEXITY: O(V + E)
 * --> bridge: any edge which on removal will divide the graph into two or
 *  more SCCs (strongly connected components)
 *
 * ALGORITHM:
 *   dfs from any node u. mark:
 *   1. discovery time of current node (disc[u]) = lowest time of discovery
 * of current (low[u]) node.
 *   3. discovery time and lowest time of discovery of child node (v) if not
 * visited.
 *   4. IF low[v] <= disc[u]: low[u] = low[v]
 *     ELSE: bridges.push_back({u, v})
 * ...
 *   -> low[v] <= disc[u] implies:
 *      child has an adjacent node connecting the current node apart from the
 * edge between them. This indicates the child and the current node do not
 * form a bridge.
 *   -> low[v] > disc[u] implies:
 *       child has only one connection to current node. This indicates child
 * and current node form a bridge.
 * */
#pragma once
#include <vector>  // std::vector

class Tarjan {
 public:
  std::vector<std::vector<int>> stronglyConnected(
      int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> adj;
    for (int i = 0; i < n; i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }
    std::vector<int> vis(n, 0), tim(n), low(n);
    std::vector<std::vector<int>> bridges;
    dfs(0, -1, vis, adj, tim, low, bridges);

    return bridges;
  }

 private:
  void dfs(int node, int parent, std::vector<int>& vis,
           std::vector<std::vector<int>>& adj, std::vector<int>& tim,
           std::vector<int>& low, std::vector<std::vector<int>>& bridges) {
    vis[node] = 1;
    tim[node] = low[node] = m_timer;
    m_timer++;
    for (const auto& it : adj[node]) {
      if (it == parent) continue;
      if (!vis[it]) {
        dfs(it, node, vis, adj, tim, low, bridges);
        low[node] = std::min(low[node], low[it]);
        if (low[it] > tim[node]) {
          bridges.push_back({node, it});
        }
      } else {
        low[node] = std::min(low[node], low[it]);
      }
    }
  }

  int m_timer = 1;
};

// int main(){
//   cout << "compiled.\n";
// }
