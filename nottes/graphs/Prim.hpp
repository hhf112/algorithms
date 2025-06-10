//PRIM'S ALGORITHM
//Time Complexity O(ElogE)
//Space Complexity O(E)
//
//    * Finds the MST (Minimum Spanning Tree)
//
//    -->  a tree in which we have N nodes and N-1 edges and all nodes are reachabe from each other 
//
//
//
#include <bits/stdc++.h>
#include <queue>
using namespace std;


class Prim {
  //from each node push all the edges into the priority queue and always 
  //add the smallest edge whcih u get from the top of the priority quuee  to the mst
  //
public:
  int spanningTree(int V, vector<vector<int>> adj[]){
    //adj[node] = [adjNode, edgeWeight]
    //only mark visited after running the iteration

    priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> pq;
    //{edgeWeight, node}

    vector<int> vis(V, 0);
    pq.push({0,0});

    int sum = 0;
    while(!pq.empty()){
      auto it = pq.top();
      pq.pop();

      auto [wt, node] = it;

      if (vis[node] == 1) continue;
      vis[node] = 1;
      sum += wt;

      for (auto& x : adj[node]){
        int adjNode = x[0], edgeWeight = x[1];

        if (!vis[adjNode]){
          pq.push({edgeWeight, adjNode});
        }
      }
    }

    return sum;
  }

  
};
