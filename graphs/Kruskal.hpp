/**
 * KRUSKAL'S ALGORITHMTime
 * Time Complexity  O(ElogE)
 *   -> used to find minimum spanning tree
 *   --> uses dsu instead of priority queue like prim.
 * */

#include <vector>  //std::std::vector

class DisjointSet {
  // impl
 public:
  DisjointSet(int n) {}
  int findUp(int u);
  void unionBySize(int u, int v);
};

class Kruskal {
  // Sort the edges and keep on adding them to the spanning tree if they don't
  // form a loop. (use dsu to check the loop if they belong to the same
  // component)
 public:
  inline int spanningTree(int V, std::vector<std::vector<int>> adj[]) {
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    for (int i = 0; i < V; i++) {
      for (auto it : adj[i]) {
        int adjNode = it[0];
        int wt = it[1];
        int node = i;

        edges.push_back({wt, {node, adjNode}});
        // no need to add the edge twice for we are using disjoint set
        // it will discard it anyway
      }
    }

    std::sort(edges.begin(), edges.end());

    int mswt = 0;
    DisjointSet dsu(V);
    for (auto it : edges) {
      int wt = it.first;
      int u = it.second.first;
      int v = it.second.second;

      if (dsu.findUp(u) != dsu.findUp(v)) {
        mswt += wt;
        dsu.unionBySize(u, v);
      }
    }

    return mswt;
  }
};
