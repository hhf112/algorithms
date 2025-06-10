//TARJAN'S ALGORITHM
//Time Complexity O(V + E)
//    * used for finding briges in graphs
//    --> any edge which one removal will divide the graph into two or more parts
//
//
#include <bits/stdc++.h>
using namespace std;

class Tarjan {
  //1. Do an initial DFS marking the time of first occurance of each element.
  //(Time represents the order in which the elements are traversed).
  //
  //1. After reaching an end assign the time  of the time of the node to the minimum of its adjacent
  //(not considering the parent).
  //
  //1. now check from the previous node if it can be a bridge.
  //
  //(edge can be a bridge if its lowest time is smaller than the other edge which means it can reach the other 
  //edge regardless of the break thrrough it's adjacent edge).
  //

private:
  //timer for the currnt iteration
  int timer = 1;

  void dfs (int node, int parent, vector<int>& vis, 
            vector<vector<int>>& adj, vector<int>& tim, 
            vector<int>& low, vector<vector<int>>& bridges)
  {
    vis[node] = 1;
    tim[node] = low[node] = timer;

    int child{};
    for (auto it: adj[node]){
      if (it == parent) continue;
      if (!vis[it]){
        dfs(it, node, vis, adj, tim, low, bridges);

        low[node] = min(low[node], low[it]);
        if (low[it] > tim[node]) {
          bridges.push_back({node, it});
        }
        
        child++;
      }
      else  {
        low[node] = min(low[node], low[it]);
      }
    }


  }
public: 

  vector<vector<int>> 
  stronglyConnected(int n, vector<vector<int>>& edges){

    vector<vector<int>> adj;
    for (int i = 0; i<n; i++){
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> vis (n, 0);

    vector<int> tim(n), low (n);

    vector<vector<int>> bridges;
    dfs(0, -1 , vis , adj ,tim , low , bridges);

    return bridges;
  }

};
