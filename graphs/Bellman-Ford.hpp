//BELLMAN FORD ALGROITHM
//  
//    * used for shortest path in case we have negative edges and negative cycles where dijkstra fails.
//    --> only applicable on directed graphs (convert undirected to directed)
// 
//
//
#include <bits/stdc++.h>
using namespace std;

class BellmanFord{
  //
  // O(V x E)
  vector<int> 
  inline bellman_ford(int V, vector<vector<int>>& edges, int S){
    //inital distances array
    vector<int> dist(V, 1e9);
    dist[S] = 0;


    //V vertices, V-1 'relaxations'
    for (int i = 0; i<V-1; i++){
      for (auto& it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v]){
          dist[v] = dist[u] + wt;
        }
      }
    }

    //if we do one more relaxation and find smaller distances
    // it implies we have a negative cycle in the graph.

    //Finally array of distances
    return dist;
  }
};
