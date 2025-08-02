//KAHN ALOGITHM
//
//* Topological sorting algorithm 
//              Topological sort --> if there exists an edge from u to v, u should come before v in  an array sorting of all vertices
//                               --> ONLY APPLICABLE ON DAG (Directed Acyclic Graph)
//* BFS
//
#include <bits/stdc++.h>
using namespace std;


class Kahn {
public:
  vector<int> kahn (int V, vector<int> adj[]){
    
    // C99 standard variable length array int indegree[V] = {0};
    vector<int> indegree(V, 0);

    for (int i = 0; i<V; i++){
      for (auto& it : adj[i]){
        indegree[it]++;
      }
    }

    queue<int> q;
    for (int i = 0; i<V; i++){
      if (indegree[i] == 0) 
        q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
      int node = q.front();
      q.pop();
      topo.push_back(node);

      for (auto it : adj[node]){
        indegree[it]--;
        if (indegree[it] == 0 )q.push(it);
      }

    }

    return topo;
  }
};
