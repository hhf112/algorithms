//KOSARAJU'S ALGORITHM
//Time Complexity = O(V + E)
//Space Complexity = O(V + E)
//
//    * used to find the strongly connnected components int a graph
//
//    --> Strongly connected components: 
//            a group of nodes where
//          ->each node is reachable from another node

#include <bits/stdc++.h>
using namespace std;


class Kosaraju {
  //1. Sort the nodes according to finishing time  
  //    --> do a recursive dfs and wherever we recur first gets the lowest finishing time and so on
  //
  //2. Reverse the graph 
  //
  //3. Iterate through the sorted nodes
  //    -->perform dfs if not visited
  //    --> it's a reversed graph so whenever u reach a non strongly connected node your dfs will conclude
  //    --> number of strongly connected components = no. of times dfs is invoked
  //    --> strongly connected components = the group of the nodes traversed in each dfs
  //    
private:
  void dfs (int i, vector<int>& visited, vector<int> adj[], stack<int>& st){
    visited[i]  = 1;
    for (auto it: adj[i]){
      if (!visited[it]){
        dfs(it, visited, adj, st);
      }
    }

    st.push(i);
  }

  void dfs3 (int node, vector<int>& vis, vector<vector<int>> adjT){
    vis[node] = 1;
    for (auto it : adjT[node]){
      if (!vis[it]){
        dfs3(it, vis, adjT);
      }
    }
  }

public: 
  int kosraju (int V, vector<int> adj[]){

    vector<int> vis (V, 0);
    stack<int> st;
    for (int i = 0; i<V; i++){
      if (!vis[i]){
        dfs(i, vis, adj,st);
      }
    }

    vector<vector<int>> adjT;

    for (int i = 0; i<V; i++){
      vis[i] = 0;
      for (auto it:  adj[i]){
        adjT[it].push_back(i);
      }
    }

    int scc = 0;
    while(!st.empty()){
      int node = st.top();
      st.pop();

      if (!vis[node]){
        scc++;
        dfs3(node, vis, adjT);
        //collect nodes off scc here
      }
    }

    return scc;
  }

};
