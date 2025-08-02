/**
 * PRIM's ALGORITHM: find MST.
 *
 * TIME COMPLEXITY: O(E LogV)
 * SPACE COMPLEXITY: O(E)
 *  -> MST: minimum spanning tree.
 *  -> use when working with adjacency lists and the graph is dense.
 *
 *  ALGORITHM:
 *  bfs maintaining min-heap priority queue for every edge and edge weight
 * adjacent to last node u. do:
 *  1. if visited continue.
 *  2. add current edge to mst.
 *  3. mark current node as visited.
 *  4. push all adjacent nodes into the priority queue.
 *  5. increment the sum of edges in mst.
 *  ...
 *  Greedily keep choosing the minimum edge.
 */
#pragma once
#include <queue> // std::priority_queue
#include <vector> // std::vector

class Prim {
 public:
  inline int spanningTreeLength(int V, std::vector<std::vector<int>> adj[]) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                   std::greater<std::pair<int, int>>>
        pq;
    std::vector<int> vis(V, 0);
    // std::vector<std::pair<int, int>> mst;
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
      const auto& [wt, node] = pq.top();
      pq.pop();
      if (vis[node] == 1) continue;
      vis[node] = 1;
      sum += wt;
      // mst.emplace_back(wt, node);
      for (auto& x : adj[node]) {
        if (!vis[x[0]]) {
          pq.push({x[1], x[0]});
        }
      }
    }
    return sum;
  }
};

// #include <iostream>
// int main() {
//   std::cout << "compiled.\n";
//   return 0;
// }
