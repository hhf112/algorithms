//BIPARTITE GRAPH
//      Formal defination.
//      * The graph should be dividable into two groups such that
//          -> There exists no edge between twp elements of the same group. (Disjoint Set)
//          -> An element occurs only in one group. (Independent Set)
//
//      Hence a Bipartite graph is a graph which can be divided into two groups which 
//      follow both the conditions => Independent + Disjoint.
//
//
//      Aanother way to look at the same.
//      * Color the graph with 2 colors such that no adjacent nodes
//      have the same color.
//
//      --> Linear grpahs with no cycle are always bipartite.
//      --> Any graph with an even cycle length is also bipartite.
//
#include <bits/stdc++.h>
using namespace std;


//checking using bfs

class Bipartite {
private: 

  //componentwise coloring
  bool check_dfs (int start,  vector<vector<int>>& adj,
                  vector<int>& color) {
    color[start] = 0;
    stack<int> st;
    st.push(0);
    int current_color = 0;
    while(!st.empty()){
      int cur = st.top();
      st.pop();


      for (auto& it : adj[cur]){
        if (color[it] == -1){
          color[it] = !color[cur];
          st.push(it);
        }

        else if (color[it] == color[cur]) return false;
      }
    }

    return false;
  }

  bool check_bfs(int start, vector<vector<int>>& adj,
             vector<int>& color) {
    queue<int> q;
    q.push(start);
    
    color[start] = 0;

    while (!q.empty()){
      int node = q.front ();
      q.pop();

      for (auto it: adj[node]){

        if (color[it] == -1) {
          color[it] = !color[node];
          q.push(it);
        }

        else if (color[it] == color[node]) 
            return false;
      }
    }

    return true;
  }

public:
  bool isBipartite_bfs (int n, vector<vector<int>>& adj) {
    vector<int> color (n, 0);

    for (int i=0; i<n; i++)
      color[i] = -1;

    for (int i = 0; i<n; i++){
      if (color[i] == -1)
        if (!check_bfs(i, adj, color))
          return false;
    }
    return true;
  }

  bool isBipartite_dfs (int n, vector<vector<int>>& adj) {
    vector<int> color (n, 0);

    for (int i=0; i<n; i++)
      color[i] = -1;

    color[0] = 0;

    for (int i = 0; i<n; i++){
      if (color[i] == -1)
        if (!check_dfs(i, adj, color))
          return false;
    }
    return true;
  }
};
  
