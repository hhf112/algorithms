//FLOYD WARSHALL ALGORITHM
//Time Complexity O(n^3)
//Space Complexity  = O(n^2) including the given adjacency matrix
//
//* Multi source shortest distance algorithm
//          --> Dijkstra for every individual node is faster but won't work for negative cycle
//
// Find the shortest path from any node to any other node in the graph
// Detects negative cycles in the graph
// Applicable on directed and undirected graphs both


#include <bits/stdc++.h>
using namespace std;

class FloydWarshall {
  //go via every vertex
  //use dp
  //d[i][j] = d[i][k] + d[k][j]
  //iterate over all k
  //iterate over all i and j for the entire adjacency matrix

public:
  //done in place
  inline void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();

    //initialzie ditances
    for (int i = 0; i<n; i++){
      for (int j = 0; j<n; j++){
        if (matrix[i][j] == -1) 
          matrix[i][j] = 1e9;

        if (i == j) 
          matrix[i][j] = 0;
      }
    }

    //Algorithm O(n^3)
    for (int k = 0; k<n; k++){
      for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
          matrix[i][j] = min(matrix[i][j], 
         matrix[i][k] + matrix[k][j]);
        }
      }
    }

    //if distance to any node remains infinite set it to -1
    for (int i = 0; i<n; i++){
      for (int j = 0; j<n; j++){
        if (matrix[i][j] == 1e9) 
          matrix[i][j] = -1;
      }
    }

    for (int i = 0; i<n; i++){
      for (int j = 0; j<n; j++){
        if (matrix[i][j] < 0) {
          /*negative cycle detected*/
        }
      }
    }
  }

};
