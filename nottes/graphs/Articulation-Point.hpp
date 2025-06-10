//ARTICULATION POINT
//     * used to find vertices in graph on removal of which the graph is divided into 
//     multiple parts
//
#include <bits/stdc++.h>
using namespace std;


class Articulation {
  // --> same as tarjan
  //  --> slight condition change
  //      -> low[it] >= tim[node]
  //
  //  -->separte consideration for the start of the graph

private: 
  int timer = 0;
public:
  void dfs(int node, int parent, 
           vector<int>& tim, vector<int>& low,
           vector<int>& vis,
           vector<int>& mark, 
           vector<vector<int>>& adj) 
  {
    vis[node] = 1;
    tim[node] = low[node] = timer;
    timer++;

    int child = 0;
    for (auto& it: adj[node]){
      if (it == parent) continue;
      if (!vis[it]){
        dfs(it, node, vis, tim, low, mark ,adj);
        
        low[node] = min(low[node], low[it]);

        if (low[it] >= tim[node] && parent != -1) 
          mark[it] = 1;


        child++;
      }
      else {
        low[node] = min(low[node], tim[it]);
      }

      if (child > 1 && parent == -1)
        mark[node] = 1;
    }

  }

  vector<int> 
  findArticulation (int n, vector<vector<int>>& adj) {
    vector<int> vis(n, 0);
    vector<int> tim(n), low(n);
    vector<int> mark(n, 0);

    for (int i =0 ;i<n; i++){
      if (!vis[i]){
        dfs(i , -1 , tim , low , vis , mark 
            , adj);
      }
    }

    vector<int> ans;
    for (int i = 0; i<n; i++){
      if (mark[i] == 1) 
        ans.push_back(i);
    }

    if (!ans.size()) return {-1};
    return ans;
  }
  
  

};


